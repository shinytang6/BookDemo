## css中line-height属性的一些应用

### 字面意思

“行高”顾名思意指一行文字的高度。具体来说是指两行文字间基线之间的距离

### 一个误解

css中起高度作用的应该就是height以及line-height了。

先说一个大家都熟知的现象，有一个空的div,

如果没有设置至少大于1像素高度height值时，该div的高度(height)就是0。

如果该div里面打入了一个空格或是文字，则此div就会有一个高度。

通常我们都普遍认为：**是文字撑开的**

但是事实上，深入理解inline模型后，根本不是文字撑开了div的高度，而是**line-height**!

证明代码如下：

	<!DOCTYPE html>
	<html>
	<head>
	   <style type="text/css">
	    .test1{font-size:20px; line-height:0; border:1px solid red; background:gray;}
	    .test2{font-size:0; line-height:20px; border:1px solid red; background:gray;margin-top: 100px;}
	   </style>
	</head>
	<body>
		<div class="test1">测试</div>
		<div class="test2">测试</div>
	</body>
	</html>

##### 在inline box模型中，有个line boxes，这玩意是看不见的，这个玩意的工作就是包裹每行文字。一行文字有一个line-height。

### 垂直居中

##### 单行文字的垂直居中对齐

网上都是这么说的，把line-height值设置为height一样大小的值可以实现单行文字的垂直居中。确实我看了很多视频中代码也是这么写的

但很多时候这个height是多余的。


具体介绍参考：

[css行高line-height的一些深入理解及应用](http://www.zhangxinxu.com/wordpress/2009/11/css%E8%A1%8C%E9%AB%98line-height%E7%9A%84%E4%B8%80%E4%BA%9B%E6%B7%B1%E5%85%A5%E7%90%86%E8%A7%A3%E5%8F%8A%E5%BA%94%E7%94%A8/)