## MVC中的URL路由系统
###

#### 一. URL

	百度百科：URL，即统一资源定位符，

	是对可以从互联网上得到的资源的位置和访问方法的一种简洁的表示，是互联网上标准资源的地址。

	互联网上的每个文件都有一个唯一的URL，它包含的信息指出文件的位置以及浏览器应该怎么处理它。

#### 二. MVC中的URL路由

	Url路由系统最初是为了实现请求url与物理文件路径分离而建立的，
	
	MVC中的Url Route是将Url地址与物理文件映射转移到了目标Controller的映射。

	一般来说，目标Controller和Action的名称由请求的URL决定， 

	URL路由系统通过对请求的拦截和对请求URL的解析，

	得到以Controller和Action名称为核心的路由数据。



参考文档：[http://blog.csdn.net/onlybymyself/article/details/50533393](http://blog.csdn.net/onlybymyself/article/details/50533393)