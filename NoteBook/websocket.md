## WebSocket
###

>这两天接触到websocket这东西,好像发现新大陆一般，在此转载一篇觉得写得很好的文。

#### 一. WebSocket是HTML5出的东西（协议），也就是说HTTP协议没有变化，或者说没关系，但HTTP是不支持持久连接的（长连接，循环连接的不算）

首先HTTP有1.1和1.0之说，也就是所谓的keep-alive，把多个HTTP请求合并为一个，

但是Websocket其实是一个新协议，跟HTTP协议基本没有关系，只是为了兼容现有浏览器的握手规范而已，也就是说它是HTTP协议上的一种补充.

#### 二. Websocket是什么样的协议，具体有什么优点

首先，Websocket是一个持久化的协议，相对于HTTP这种非持久的协议来说。

1) HTTP的生命周期通过Request来界定，也就是一个Request 一个Response，那么在HTTP1.0中，这次HTTP请求就结束了。

在HTTP1.1中进行了改进，使得有一个keep-alive，也就是说，在一个HTTP连接中，可以发送多个Request，接收多个Response。

但是请记住 Request = Response ， 在HTTP中永远是这样，也就是说一个request只能有一个response。而且这个response也是被动的，不能主动发起。

教练，你BB了这么多，跟Websocket有什么关系呢？

首先Websocket是基于HTTP协议的，或者说借用了HTTP的协议来完成一部分握手。在握手阶段是一样的

首先我们来看个典型的Websocket握手（借用Wikipedia的。。）

	GET /chat HTTP/1.1
	Host: server.example.com
	Upgrade: websocket
	Connection: Upgrade
	Sec-WebSocket-Key: x3JJHMbDL1EzLkh9GBhXDw==
	Sec-WebSocket-Protocol: chat, superchat
	Sec-WebSocket-Version: 13
	Origin: http://example.com

以下就是Websocket的核心了，告诉Apache、Nginx等服务器：注意啦，窝发起的是Websocket协议，快点帮我找到对应的助理处理~不是那个老土的HTTP。

	Upgrade: websocket
	Connection: Upgrade


然后服务器会返回下列东西，表示已经接受到请求， 成功建立Websocket啦！

	HTTP/1.1 101 Switching Protocols
	Upgrade: websocket
	Connection: Upgrade
	Sec-WebSocket-Accept: HSmrc0sMlYUkAGmm5OPpG2HaGWk=
	Sec-WebSocket-Protocol: chat


>那到底Websocket有什么鬼用，http long poll，或者ajax轮询不都可以实现实时信息传递么。

#### 三. Websocket的作用

在讲Websocket之前，我就顺带着讲下 long poll 和 ajax轮询 的原理。

首先是 ajax轮询 ，ajax轮询 的原理非常简单，让浏览器隔个几秒就发送一次请求，询问服务器是否有新信息。

	场景再现：
	客户端：啦啦啦，有没有新信息(Request)
	服务端：没有（Response）客户端：啦啦啦，有没有新信息(Request)
	服务端：没有。。（Response）
	客户端：啦啦啦，有没有新信息(Request)
	服务端：你好烦啊，没有啊。。（Response）
	客户端：啦啦啦，有没有新消息（Request）
	服务端：好啦好啦，有啦给你。（Response）
	客户端：啦啦啦，有没有新消息（Request）
	服务端：。。。。。没。。。。没。。。没有（Response） ---- loop


long poll 

long poll 其实原理跟 ajax轮询 差不多，都是采用轮询的方式，不过采取的是阻塞模型（一直打电话，没收到就不挂电话），

也就是说，客户端发起连接后，如果没消息，就一直不返回Response给客户端。直到有消息才返回，返回完之后，客户端再次建立连接，周而复始。

	场景再现：
	客户端：啦啦啦，有没有新信息，没有的话就等有了才返回给我吧（Request）
	服务端：额。。   等待到有消息的时候。。来 给你（Response）
	客户端：啦啦啦，有没有新信息，没有的话就等有了才返回给我吧（Request） -loop



从上面可以看出其实这两种方式，都是在不断地建立HTTP连接，然后等待服务端处理，可以体现HTTP协议的另外一个特点，**被动性**。

何为被动性呢，其实就是，服务端不能主动联系客户端，只能有客户端发起。

简单地说就是，服务器是一个很懒的冰箱（这是个梗）（不会、不能主动发起连接），但是上司有命令，如果有客户来，不管多么累都要好好接待。

看完这个，我们再来说一说上面的缺陷，从上面很容易看出来，不管怎么样，上面这两种都是非常消耗资源的。

ajax轮询 需要服务器有很快的处理速度和资源。（速度）

long poll 需要有很高的并发，也就是说同时接待客户的能力。（场地大小）

所以ajax轮询 和long poll 都有可能发生这种情况。

	客户端：啦啦啦啦，有新信息么？
	服务端：月线正忙，请稍后再试（503 Server Unavailable）
	客户端：。。。。好吧，啦啦啦，有新信息么？
	服务端：月线正忙，请稍后再试（503 Server Unavailable）


Websocket的出现解决了HTTP的这几个难题

首先，**被动性**，当服务器完成协议升级后（HTTP->Websocket），服务端就可以主动推送信息给客户端啦。

所以上面的情景可以做如下修改。

	客户端：啦啦啦，我要建立Websocket协议，需要的服务：chat，Websocket协议版本：17（HTTP Request）
	服务端：ok，确认，已升级为Websocket协议（HTTP Protocols Switched）
	客户端：麻烦你有信息的时候推送给我噢。。
	服务端：ok，有的时候会告诉你的。
	服务端：balabalabalabala
	服务端：balabalabalabala
	服务端：哈哈哈哈哈啊哈哈哈哈
	服务端：笑死我了哈哈哈哈哈哈哈

就变成了这样，只需要经过一次HTTP请求，就可以做到源源不断的信息传送了。

在程序设计中，这种设计叫做回调，即：你有信息了再来通知我，而不是我傻乎乎的每次跑来问你）

这样的协议解决了上面同步有延迟，而且还非常消耗资源的这种情况。

##### 在传统的方式上，要不断的建立，关闭HTTP协议，由于HTTP是非状态性的，每次都要重新传输identity info（鉴别信息），来告诉服务端你是谁。

##### 但是Websocket只需要一次HTTP握手，所以说整个通讯过程是建立在一次连接/状态中，也就避免了HTTP的非状态性，

##### 服务端会一直知道你的信息，直到你关闭请求。



##

转自：[https://www.zhihu.com/question/20215561/answer/40316953](https://www.zhihu.com/question/20215561/answer/40316953)
