## 用户界面样式
###

### 一. 系统字体和颜色

##### 系统字体

CSS2定义了6个系统字体关键字：

* caption
* icon
* menu
* message-box
* small-caption
* status-bar

这些值只能用于`font`属性，它们本身就是简写形式

如下面三个规则等价

	body {font: icon;}
	body {font: 10px Geneva;}
	body {
	font-weight: normal;
	font-style: normal;
	font-variant: normal;
	font-size: 10px;
	font-family: Geneva;
	}

##### 系统颜色

系统颜色关键字：

* Background
* ButtonFace
* CaptionText
* Menu
* MenuText
* Window
* WindowText
* ...

### 二. 光标

##### 改变光标

属性：`cursor`

值：

* url()
* auto
* pointer
* crosshair
* move
* text
* wait
* help
* progress
* e-resize
* ne-resize
* ...

如：

	p {cursor: wait;}
	// 在cursor语法定义中，URL必须跟有一个逗号和某个通用关键字
	p {cursor: url(xxx.xx),pointer;}

### 三. 轮廓

轮廓有点类似于边框，不过二者有两个重要的区别

首先，轮廓不像边框那样参与到文档流中，因此轮廓出现或消失时不会影响文档流，即不会导致文档的重新显示。

如果为一个元素指定了50像素的轮廓，这个轮廓很可能会覆盖其他元素。

轮廓和边框之间还有一个根本的差异：它们不是同一个东西，所以在同一个元素上共存。

##### 轮廓样式

属性：`outline-style`

值：

* none
* dotted
* dashed
* solid
* double
* groove
* ridge
* inset
* outset
* inherit

轮廓的样式关键字与边框样式关键字基本上相同，有一个区别就是，只能为一个`outline-style`值指定一个关键字（而边框可以指定最多4个关键字）。

其实际效果就是，一个元素周围必然有相同的轮廓样式。

##### 轮廓宽度

属性：`outline-width`

值：

* thin
* medium
* thick
* 长度
* inherit

和轮廓样式一样，`outline-width`和`border-width`之间唯一真正的区别是整个轮廓只能声明一个宽度。

##### 轮廓颜色

属性：`outline-color`

值：

* 颜色
* invert
* inherit

初始值：`invert`

类似于轮廓样式和宽度，对整个轮廓只能定义一种颜色。

##### 汇总

属性：`outline`

值：`outline-color` | `outline-style` | `outline-width`

类似于设置边框样式的`border`属性。

