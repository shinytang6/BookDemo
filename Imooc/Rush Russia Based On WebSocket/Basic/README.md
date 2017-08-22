## 基于WebSocket的火拼俄罗斯（基础篇）
###


* [demo1]()
* [demo2]()
* [demo3]()
* [demo4]()
* [demo5]()
* [demo6]()

### Introduction

##### 一. Demo1

这个demo利用了websocket官网的echo服务器 `ws://echo.websocket.org` 入门

websocket官网 ： [ws://echo.websocket.org](ws://echo.websocket.org)

##### 二. Demo2

这个demo利用nodejs-websocket自己写了个本地服务器，运行在8001端口，并重新实现了Demo2例子

nodejs-websocket包地址：[https://github.com/sitegui/nodejs-websocket](https://github.com/sitegui/nodejs-websocket)

##### 三. Demo3

这个demo利用nodejs-websocket包实现了一个简单的聊天室

##### 四. Demo4

这个demo完善了demo3的聊天室，将用户进入、用户离开以及用户说话进行客户端区分

##### 五. Demo5

为了避免Demo4中的诸多麻烦：

比如Demo4中必须在服务端手动创建对象并通过 `JSON.stringify（）`转化为JSON字符串，并在客户端通过 `JSON.parse（）`将JSON解析回对象

这个demo引入了socket.io这个新的包实现了一个官网的简单实例

socke.io官网：[https://socket.io/blog/](https://socket.io/blog/)

##### 六. Demo6

这个demo用socket.io重写了demo4中的聊天室，可以说简单了许多
