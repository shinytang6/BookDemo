## 颜色和背景
###

### 一. 颜色

##### 影响边框

color的值可以影响元素周围的边框。

假设已经声明了以下样式：

	p {color: red; border-style: solid;}

元素p会有红色文本和红色中等宽度的实线边框

这是因为默认的前景色会应用到边框

要覆盖这种行为，最基本的办法是使用属性`border-color`

	p {color: red; border-style: solid; border-color: black;}

这会使文本变为红色，但边框为黑色。


### 二. 背景

##### 背景色

属性： `background-color`
 
默认值：`transparent`

##### 背景图像

首先，要把图像放入背景，需要使用属性`background-image`

其默认值为`none`，表示背景上没有放任何图像。如果你希望有一个背景图像，必须为这个属性制定一个URL值：

	body {background-image: url(xxx.gif);}

在使用背景图像时，最好再指定一个背景色`background-color`，以确保得到一个清晰的结果。

##### 有方向的重复

属性：`background-repeat`

默认值：`repeat`

基本值：

* repeat
* repeat-x
* repeat-y
* no-repeat
* inherit

显而易见，`repeat`导致图像在水平垂直方向上都平铺，就像以往背景图像的通常做法一样。`repeat-x`和`repeat-y`分别导致图像只在水平或垂直方向上重复，`no-repeat`则不允许图像在任何方向上平铺。

##### 背景定位

默认地，背景图像将会从一个元素的左上角开始

原图像的放置由`background-position`属性决定

可以使用一些关键字：

* top
* bottom
* left
* right
* center
* 百分数
* 长度值

图像放置关键字最容易理解，例如，`top right`使原图像放在元素内边距区的右上角

	p {background-image: url(xxx.gif);
	   background-repeat: no-repeat;
	   background-position: top right;}

这会在每个段落内边距右上角放置一个不重复地原图像

位置关键字可以按任何顺序出现，只要保证不能超过两个关键字——一个对应水平方向，另一个对应垂直方向。

如果只出现了一个关键字，则认为另一个关键字是`center`

##### 关联

属性：`background-attachment`

默认值：`scroll`

基本值：

* scroll
* fixed
* inherit


通过使用属性`background-attachment`，可以声明原图像相对于可是区是固定的（fixed），因此不会受滚动的影响

##### 汇总

与字体属性一样，背景属性可以汇总到一个简写属性：`background`

这个属性可以从各个其他背景属性取一个值，而且可以采用任何顺序

其值包括：

`background-color`、`background-image`、`background-repeat`、`background-attachment`、`background-position`

如果省略了某些值，就会自动填入相应属性的默认值