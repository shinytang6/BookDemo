## 表布局
###

### 一. 表格式化

##### 表的视觉编排

在CSS中，内部表元素生成矩形框，这些框有内容、内边距、边框和宽高度，但是没有外边距，声明外边距会被浏览器忽略

##### 匿名表对象

对于如下代码：

	<table>
		<td>Name:</td>
		<td><input type="text"></td>
	</table>
	
乍看这个标记，你可能认为它定义了一个包含两个单元格的单行表，不过从结构上讲，这里没有定义行的元素（因为没有tr）

考虑到这种可能性，CSS定义了一种机制，可以将"遗漏的"组件作为匿名对象插入，也就是将上述的tr自动插入。

##### 表标题

属性：`caption`

表标题是一小段文本，描述了表内容的本质

利用属性`caption-side`,可以把这个元素放在table之上，也可以放在table之下

属性：`caption-side`

值：

* top
* bottom

初始值：

* top

### 二. 表单元格边框

CSS中实际上有两种截然不同的边框模型。

按布局术语来讲，如果单元格相互之间是分隔的，就是分隔边框模型在起作用。另一种选择是合并边框模型，采用这种模型，单元格之间没有可见的间隔，单元格边框会相互合并，前者是默认模型。

属性：`border-collapse`

值：

* collapse
* separate
* inherit

初始值：`separate`

应用于：display值为table或inline-table的元素

##### 边框间隔

属性：`border-spacing`

值：length

初始值：0px

应用于：display值为table或inline-table的元素

说明：除非border-collapse值为separate,否则会忽略该属性

##### 处理空单元格

属性：`empty-cells`

值：

* show
* hide
* inherit

初始值：`show`

如果设置`table`的该值为`hide`，则不会画出空单元格，就好像这个单元格被设置为`visibility:hidden`

### 三. 表大小

##### 对齐

水平对齐是最简单的。要让一个单元格中的内容对齐，可以使用`text-align`属性。

要将一个表单元格中的内容垂直对齐，可以使用`vertical-align`属性

`vertical-align`属性应用到表单元格时只能设置以下值：

* top
* bottom
* middle
* baseline

其他值会被忽略