## 非屏幕媒体
###

可以通过`media`属性对媒体作出限制。在link和style元素中的用法是一样的。

	<link rel="stylesheet" type="text/css" media="print" href="article-print.css">

	<style type="text/css" media="projection">
	body {font-family: sans-serif;}
	</style>

CSS2还定义了`@media`块的语法，允许在同一样式表中为多个媒体定义样式。
	
	<style type="text/css">
	body {font-family: sans-serif;}
	@media screen {
		h1 {margin: 1em;}
	}
	@media print {
		h1 {margin: 2em;}
	}
	</style>
	
其他特性感觉暂时接触不到，就不再做记录。