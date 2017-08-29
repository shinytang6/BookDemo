## 浏览器同源政策以及跨域问题总结
###

### 一. 同源策略

#### 1. 定义

> 1995年，同源政策由 Netscape 公司引入浏览器。目前，所有浏览器都实行这个政策。

简单来说，它的含义是说：A网页设置的Cookie，B网页不能打开，除非这两个网页“同源”。

##### 判断同源的三个要素：

* 相同的协议
* 相同的域名
* 相同的端口号

举例来说，`http://www.example.com/dir/page.html`这个网址，协议是http://，域名是www.example.com，端口是80（默认端口可以省略）。它的同源情况如下：

	http://www.example.com/dir2/other.html：同源
	http://example.com/dir/other.html：不同源（域名不同）
	http://v2.www.example.com/dir/other.html：不同源（域名不同）
	http://www.example.com:81/dir/other.html：不同源（端口不同）

#### 2. 存在意义

> 为了保证使用者信息的安全，防止恶意网站篡改用户数据。

举个例子：

假设没有同源策略，那么我在A网站下的cookie就可以被任何一个网站拿到；那么这个网站的所有者，就可以使用我的cookie(也就是我的身份)在A网站下进行操作。

同源策略可以算是 web 前端安全的基石，如果缺少同源策略，浏览器也就没有了安全性可言。

#### 3. 限制范围

非同源的网站之间，共有三种行为受到限制：

	1）Cookie、LocalStorage 和 IndexDB 无法读取。
	2）DOM 无法获得。
	3）AJAX 请求不能发送。


### 二. 跨域

> 同源策略做了很严格的限制，但是在实际的场景中，又确实有很多地方需要突破同源策略的限制，也就是我们常说的跨域。

##### 以下介绍几种跨域方法

#### 1. Cookie

> 同源策略最早被提出的时候，为的就是防止不同域名的网页之间共享 cookie，但是如果两个网页的*一级域名是相同的*，可以通过设置 document.domain来共享 cookie。

举例来说：

A网页是`http://w1.example.com/a.html`，B网页是`http://w2.example.com/b.html`

那么只要设置相同的document.domain，两个网页就可以共享Cookie。

	document.domain = 'example.com';

现在，A网页通过脚本设置一个Cookie。

	document.cookie = "test1=hello";

B网页就可以读到这个 Cookie。

	var allCookie = document.cookie;

除了在前端设置之外，也可以直接在 response 里将 cookie 的 domain 设置成 .example.com。

	Set-Cookie: key=value; domain=.example.com; path=/

这样的话，二级域名和三级域名不用做任何设置，都可以读取这个Cookie。

#### 2. iframe

对于完全不同源的网站，目前有三种方法，可以解决跨域窗口的通信问题：

* 片段识别符（fragment identifier）
* window.name
* 跨文档通信API（Cross-document messaging）

这里就不详细展开...反正也看不懂，具体看参考。


#### 3. Ajax

> 在使用 ajax 的过程中，我们碰到的同源限制的问题是最多的。

> 同源政策规定，AJAX请求只能发给同源的网址，否则就报错。


除了架设服务器代理（浏览器请求同源服务器，再由后者请求外部服务），有三种方法规避这个限制：

* JSONP
* WebSocket
* CORS


##### JSONP

JSONP是服务器与客户端跨源通信的常用方法。最大特点就是简单适用，老式浏览器全部支持，服务器改造非常小。

它的基本思想是，网页通过添加一个`<script>`元素，向服务器请求JSON数据，这种做法不受同源政策限制；

服务器收到请求后，将数据放在一个指定名字的回调函数里传回来。

首先，网页动态插入`<script>`元素，由它向跨源网址发出请求。

	function addScriptTag(src) {
	  var script = document.createElement('script');
	  script.setAttribute("type","text/javascript");
	  script.src = src;
	  document.body.appendChild(script);
	}
	
	window.onload = function () {
	  addScriptTag('http://example.com/ip?callback=foo');
	}
	
	function foo(data) {
	  console.log('Your public IP address is: ' + data.ip);
	};


上面代码通过动态添加`<script>`元素，向服务器`example.com`发出请求。

注意，该请求的查询字符串有一个`callback`参数，用来指定回调函数的名字，这对于JSONP是必需的。

服务器收到这个请求以后，会将数据放在回调函数的参数位置返回。

	foo({
	  "ip": "8.8.8.8"
	});

由于`<script>`元素请求的脚本，直接作为代码运行。

这时，只要浏览器定义了`foo`函数，该函数就会立即调用。

作为参数的JSON数据被视为JavaScript对象，而不是字符串，因此避免了使用`JSON.parse`的步骤。


##### WebSocket

> WebSocket是一种通信协议，使用ws://（非加密）和wss://（加密）作为协议前缀。
> 
> 该协议不实行同源政策，只要服务器支持，就可以通过它进行跨源通信。

下面是一个例子，浏览器发出的WebSocket请求的头信息：

	GET /chat HTTP/1.1
	Host: server.example.com
	Upgrade: websocket
	Connection: Upgrade
	Sec-WebSocket-Key: x3JJHMbDL1EzLkh9GBhXDw==
	Sec-WebSocket-Protocol: chat, superchat
	Sec-WebSocket-Version: 13
	Origin: http://example.com

上面代码中，有一个字段是Origin，表示该请求的请求源（origin），即发自哪个域名。

正是因为有了Origin这个字段，所以WebSocket才没有实行同源政策。

因为服务器可以根据这个字段，判断是否许可本次通信。

如果该域名在白名单内，服务器就会做出如下回应。
	
		
	HTTP/1.1 101 Switching Protocols
	Upgrade: websocket
	Connection: Upgrade
	Sec-WebSocket-Accept: HSmrc0sMlYUkAGmm5OPpG2HaGWk=
	Sec-WebSocket-Protocol: chat


##### CORS

> ORS是跨源资源分享（Cross-Origin Resource Sharing）的缩写。
> 
> 它是W3C标准，是跨源AJAX请求的根本解决方法。相比JSONP只能发GET请求，CORS允许任何类型的请求。

CORS需要浏览器和服务器同时支持。目前，所有浏览器都支持该功能，IE浏览器不能低于IE10。

整个CORS通信过程，都是浏览器自动完成，不需要用户参与。

对于开发者来说，CORS通信与同源的AJAX通信没有差别，代码完全一样。

浏览器一旦发现AJAX请求跨源，就会自动添加一些附加的头信息，有时还会多出一次附加的请求，但用户不会有感觉。

###### 因此，实现CORS通信的关键是服务器。CROS的设置，大部分是需要在服务端进行设置，只要服务器实现了CORS接口，就可以跨源通信了。

##### 在服务端设置之前，先来看一下 CROS 在浏览器中是怎么运作的：

浏览器将CORS请求分成两类：简单请求（simple request）和非简单请求（not-so-simple request）。

简单请求的判断包括两个条件：

	（1) 请求方法是以下三种方法之一：
	HEAD
	GET
	POST
	（2）HTTP的头信息不超出以下几种字段：
	Accept
	Accept-Language
	Content-Language
	Last-Event-ID
	Content-Type：只限于三个值application/x-www-form-urlencoded、multipart/form-data、text/plain

凡是不同时满足上面两个条件，就属于非简单请求。

浏览器对这两种请求的处理，是不一样的。

1）简单请求

对于简单请求，浏览器直接发出CORS请求。具体来说，就是在头信息之中，增加一个`Origin`字段。

下面是一个例子，浏览器发现这次跨源AJAX请求是简单请求，就自动在头信息之中，添加一个`Origin`字段。

	ET /cors HTTP/1.1
	Origin: http://api.bob.com
	Host: api.alice.com
	Accept-Language: en-US
	Connection: keep-alive
	User-Agent: Mozilla/5.0...

上面的头信息中，`Origin`字段用来说明，本次请求来自哪个源（协议 + 域名 + 端口）。服务器根据这个值，决定是否同意这次请求。

如果`Origin`指定的源，不在许可范围内，服务器会返回一个正常的HTTP回应。

浏览器发现，这个回应的头信息没有包含`Access-Control-Allow-Origin`字段（详见下文），就知道出错了，从而抛出一个错误，被`XMLHttpRequest`的`onerror`回调函数捕获。

注意，这种错误无法通过状态码识别，因为HTTP回应的状态码有可能是200。

如果`Origin`指定的域名在许可范围内，服务器返回的响应，会多出几个头信息字段。

	Access-Control-Allow-Origin: http://api.bob.com
	Access-Control-Allow-Credentials: true
	Access-Control-Expose-Headers: FooBar
	Content-Type: text/html; charset=utf-8

上面的头信息之中，有三个与CORS请求相关的字段，都以`Access-Control-`开头。

（1）Access-Control-Allow-Origin

该字段是必须的。它的值要么是请求时`Origin`字段的值，要么是一个`*`，表示接受任意域名的请求。

（2）Access-Control-Allow-Credentials

该字段可选。它的值是一个布尔值，表示是否允许发送Cookie。

默认情况下，Cookie不包括在CORS请求之中。

设为`true`，即表示服务器明确许可，Cookie可以包含在请求中，一起发给服务器。

这个值也只能设为`true`，如果服务器不要浏览器发送Cookie，删除该字段即可。

（3）Access-Control-Expose-Headers

该字段可选。CORS请求时，`XMLHttpRequest`对象的`getResponseHeader()`方法只能拿到6个基本字段：

`Cache-Control`、`Content-Language`、`Content-Type`、`Expires`、`Last-Modified`、`Pragma`。

如果想拿到其他字段，就必须在`Access-Control-Expose-Headers`里面指定。

上面的例子指定，`getResponseHeader('FooBar')`可以返回`FooBar`字段的值。

##

上面说到，CORS请求默认不发送Cookie和HTTP认证信息。

如果要把Cookie发到服务器，一方面要服务器同意，指定`Access-Control-Allow-Credentials`字段。

	Access-Control-Allow-Credentials: true

另一方面，开发者必须在AJAX请求中打开`withCredentials`属性。

	var xhr = new XMLHttpRequest();
	xhr.withCredentials = true;

否则，即使服务器同意发送Cookie，浏览器也不会发送。或者，服务器要求设置Cookie，浏览器也不会处理。

但是，如果省略`withCredentials`设置，有的浏览器还是会一起发送Cookie。这时，可以显式关闭`withCredentials`。

	xhr.withCredentials = false;

##### 需要注意的是，如果要发送Cookie，Access-Control-Allow-Origin就不能设为星号，必须指定明确的、与请求网页一致的域名。

2）非简单请求

> 与简单请求最大的不同在于，非简单请求实际上是发送了两个请求。

非简单请求的CORS请求，会在正式通信之前，增加一次HTTP查询请求，称为"预检"请求（preflight）。

浏览器先询问服务器，当前网页所在的域名是否在服务器的许可名单之中，以及可以使用哪些HTTP动词和头信息字段。

只有得到肯定答复，浏览器才会发出正式的XMLHttpRequest请求，否则就报错。

以下是一个"预检"请求的HTTP头信息。

	OPTIONS /cors HTTP/1.1
	Origin: http://api.bob.com
	Access-Control-Request-Method: PUT
	Access-Control-Request-Headers: X-Custom-Header
	Host: api.alice.com
	Accept-Language: en-US
	Connection: keep-alive
	User-Agent: Mozilla/5.0...

"预检"请求用的请求方法是`OPTIONS`，表示这个请求是用来询问的。头信息里面，关键字段是`Origin`，表示请求来自哪个源。

除了`Origin`字段，"预检"请求的头信息包括两个特殊字段。

（1）Access-Control-Request-Method

该字段是必须的，用来列出浏览器的CORS请求会用到哪些HTTP方法，上例是PUT。

（2）Access-Control-Request-Headers

该字段是一个逗号分隔的字符串，指定浏览器CORS请求会额外发送的头信息字段，上例是X-Custom-Header。


服务端收到预请求之后会根据request中的`origin`,`Access-Control-Request-Method`和`Access-Control-Request-Headers`判断是否响应该请求。

如果预请求被正确响应，接下来就会发送正式请求，正式请求的request和正常的ajax请求基本没有区别

只是会携带`origin`字段；response和简单请求一样，会携带上`Access-Control-*`这些字段。

###### CORS与JSONP的比较

> CORS与JSONP的使用目的相同，但是比JSONP更强大。
>
> JSONP只支持`GET`请求，CORS支持所有类型的HTTP请求。
> 
> JSONP的优势在于支持老式浏览器，以及可以向不支持CORS的网站请求数据。


参考文章：

* [浏览器同源政策及其规避方法](http://www.ruanyifeng.com/blog/2016/04/same-origin-policy.html)
* [跨域资源共享 CORS 详解](http://www.ruanyifeng.com/blog/2016/04/cors.html)
* [同源策略和跨域](https://segmentfault.com/a/1190000007366644)