## Form表单中的enctype属性
###

> 今天在用postman做api测试时碰到了这个问题，于是百度学习了下。


这里介绍两种form表单常用上传的编码类型（设置在form标签中的enctype属性中）：

* application/x-www-form-urlencoded
* multipart/form-data

#### 一. x-www-form-urlencoded

当action为get时候，浏览器用`x-www-form-urlencoded`的编码方式把form数据转换成一个字串

比如（name1=value1&name2=value2…），然后把这个字串append到url后面，用?分割，加载这个新的url。

server端通过`request.getParameter`是可以取到值的。 

#### 二. multipart/form-data

当action为post时候，浏览器把form数据封装到http body中，然后发送到server。

1）如果必须要上传文件，enctype默认为`x-www-form-urlencoded`，无需设置它。

此时用`request.getParameter`是可以取到数据的 

2）如果要上传文件，就要将enctype设置为`multipart/form-data`。

表单数据都保存在http的正文部分，各个表单项之间用boundary隔开。

用`request.getParameter`是取不到数据的，这时需要通过`request.getInputStream`来取数据。

简而言之：

> multipart/form-data与x-www-form-urlencoded区别在于：
>
> multipart/form-data：既可以上传文件等二进制数据，也可以上传表单键值对，只是最后会转化为一条信息。     
>       
> x-www-form-urlencoded：只能上传键值对，并且键值对都是间隔分开的。


参考文章：

* [HTTP中application/x-www-form-urlencoded字符说明](http://blog.csdn.net/qq_28702545/article/details/51719199)
* [postman中 form-data、x-www-form-urlencoded、raw、binary的区别](http://blog.csdn.net/ye1992/article/details/49998511)
* [form enctype:"multipart/form-data",method:"post" 提交表单，后台获取不到数据](http://www.cnblogs.com/greenteaone/p/4186619.html)