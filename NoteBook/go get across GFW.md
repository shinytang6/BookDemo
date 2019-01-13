## go get 命令被墙问题
###

> 对Go开发者比较痛苦的是，golang.org网站以及其它的一些相关的开发网站被GFW屏蔽了。下载Go开发包还容易些，国内有一些镜像站点，或者通过一些代理也能访问，但是下载一些开发库的时候，这些库可能直接或者间接引用了 ｀golang.org/x/...｀等依赖库， 通过go get命令确没有办法下载下来。

如果有自己的VPN的话，应该比较好的解决。我使用的是代理ss，ss虽然能访问一些屏蔽的站点比如golang.org,但是它基于socks5协议，对于`go get`来说，依然不可用。

下一步就是想办法将socks5代理转为http代理了。

我使用的是 `cow` 这个工具, 这是shadowsocks-go作者的另一个开发项目，根据项目介绍很容易的配置,可以在本机启动一个http代理，以shadowsocks为二级代理。

#### 安装

	curl -L git.io/cow | bash
	# 或者 mac下
	brew install cow
	
#### 配置

cow软件配置：`$HOME/.cow/rc`

	# 默认已添加
	listen = http://127.0.0.1:7777 
	# 填入自己拥有的socks5代理服务器地址和端口(我本地是socks5://127.0.0.1:1086)
	proxy = socks5://127.0.0.1:1086
	
然后设置环境变量，就可以go get被屏蔽的库了, 在mac环境变量配置文件：~/.zshrc中添加

	export http_proxy=http://127.0.0.1:7777
	export https_proxy=http://127.0.0.1:7777
	
#### 启动
	# 后台方式启动
	cow & # 监听在7777端口

ref:

1. [https://blog.csdn.net/ys5773477/article/details/73929161?utm_source=blogxgwz8](https://blog.csdn.net/ys5773477/article/details/73929161?utm_source=blogxgwz8)
2. [https://colobu.com/2017/01/26/how-to-go-get-behind-GFW/](https://colobu.com/2017/01/26/how-to-go-get-behind-GFW/)