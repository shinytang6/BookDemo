## ubuntu终端使用privoxy代理
###

> 本文介绍如何在ubuntu终端利用privoxy越过GFW

在ubuntu下, 搭建完ss还需要一步配置才可以访问外网

1. 进入全部设置->网络->网络代理, 配置好网络代理
2. 使用chrome的SwitchyOmega插件(同样需要配置上述网络代理)

上述任何一种只要配置正确, 即可无障碍访问外网, 原理都是一样的:

它们都是把对外的HTTP/HTTPS流量转换成了socks5协议的流量, 因此才能通过ss发送到ss server(国外vps)上

但是, ubuntu终端是没有这样的协议转换的, ubuntu终端只认http_proxy和https_proxy两个环境变量, 所以没法直接使用socks5代理. 这时候就需要一个协议转换器, 例如Privoxy

### 具体搭建方法

1. 安装Privoxy

       sudo apt-get install privoxy
       
2. 修改配置文件

       vim /etc/privoxy/config
       
       在文件末尾添加如下内容
       forward-socks5 / 127.0.0.1:1086 . # SOCKS5代理地址
       listen-address 127.0.0.1:7777     # HTTP代理地址
       forward 10.*.*.*/ .               # 内网地址不走代理
       forward .abc.com/ .               # 指定域名不走代理
       
       其中第1行的127.0.0.1:1086是你在本地的socks5代理地址, 而第二行的127.0.0.1:7777则是socks5转换成的http代理地址(这里的端口设置随意, 只需要和后面匹配以及不被占用即可), 最后两行指定了两个不走代理的地址
       所以这几行需要根据自己的实际情况以及需求进行设置...
       
3. 重启Privoxy服务
       
       sudo /etc/init.d/privoxy restart
       
4. 在命令行设置http_proxy和https_proxy两个环境变量

       export http_proxy="127.0.0.1:7777"
       export https_proxy="127.0.0.1:7777"
       
这时, 在终端用curl ipinfo.io 测试一下公网出口IP, 发现自己已经置身墙外:), 然后终端就可以访问外网了!

ref:

1. [https://www.codelast.com/%E5%8E%9F%E5%88%9B-ubuntu%E7%BB%88%E7%AB%AF%E4%BD%BF%E7%94%A8privoxy%E4%BB%A3%E7%90%86/](https://www.codelast.com/%E5%8E%9F%E5%88%9B-ubuntu%E7%BB%88%E7%AB%AF%E4%BD%BF%E7%94%A8privoxy%E4%BB%A3%E7%90%86/)