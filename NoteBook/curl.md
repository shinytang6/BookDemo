## Curl网站开发
###

curl是一种命令行工具，作用是发出网络请求，然后得到和提取数据，显示在"标准输出"（stdout）上面。

#### 一.查看网页源码

	$ curl 网址

#### 二.显示头信息

	$ curl -I 网址

#### 三.显示头信息

	$ curl -v 网址

#### 四.发送表单信息

发送表单信息有GET和POST两种方法。

GET方法：
	
	$ curl 'example.com/form.cgi?data=xxx'

POST方法：

	$ curl -X POST --data "data=xxx" 'example.com/form.cgi'

#### 五.HTTP动词

curl默认的HTTP动词是GET，使用`-X`参数可以支持其他动词。

#### 六.增加头信息

比如：

	$ curl --header/-H "Content-Type:application/json" 'http://example.com'

#### 其他参数

	$ curl --help

#### 总结

这玩意可以说是神器了，比起在js代码中写ajax请求高多了！！！