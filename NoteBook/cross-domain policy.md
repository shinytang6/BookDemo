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

###### CROS 的设置，大部分是需要在服务端进行设置，在服务端设置之前，先来看一下 CROS 在浏览器中是怎么运作的：