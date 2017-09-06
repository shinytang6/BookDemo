## CSS中@import指令
###

> 其实这是本书第一章里的内容，这里合并到第二章说明一下。

`@import`指令和`link`指令非常相似

	@import url(xxx.css);

与`link`类似，`@import`用于指示Web浏览器加载一个外部样式表，并在表现HTML时使用其样式。

唯一的区别在于命令的具体语法和位置。

`@import`指令出现在style容器中。（可以是外部的css文件，也可以是html文件的style标签内）

`@import`语法有两种：
	
	@import "xxx.css";
	@import url("xxx.css");

这两种语法并没什么差别。

还要注意，`@import`指令出现在样式表的开头。CSS要求`@import`指令出现在样式表中的其他规则之前。