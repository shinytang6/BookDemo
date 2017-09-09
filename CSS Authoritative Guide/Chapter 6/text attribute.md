## 文本属性
###

### 一. 缩进和水平对齐

##### 缩进本文

CSS中实现文本缩进的属性：`text-indent`

如：

	p {text-indent: 3em;}

一般地，可以为所有**块级元素**应用`text-indent`,但无法将这个属性应用到**行内元素**，图像之类的**替换元素**上（如img/input等）也无法应用该属性。

##### 水平对齐

与`text-indent`相比，`text-align`是一个更基本的属性

其一般值为：

* left
* center
* right
* justify
* inherit

`text-align`只应用于**块级元素**（如段落），所以无法将行内的一个锚居中而不影响行中的其余部分

### 二. 垂直对齐

##### 行高

`line-height`属性是指文本行基线之间的距离，而不是字体的大小

`line-height`控制了行间距，这是文本行之间超出字体大小的额外空间

换句话说，`line-height`值和字体大小只差就是行间距（行上边距和行下边距之和）

> 不同的用户代理默认使用的值可能不同，不过通常都是字体大小的1.2倍

##### 垂直对齐文本

在CSS中，`vertical-align`属性只应用于**行内元素**和**替换元素**

其值：

* baseline
* sub
* super
* top 
* text-top
* middle
* bottom
* text-bottom
* 百分数
* 长度
* inherit

这个属性在实战中多在一张图片后跟文字中用到

### 三. 字间隔和字母间隔

##### 字间隔

`word-spacing`属性接受一个正长度值或负长度值，这个长度会增加到字之间的标准间隔

实际上，`word-spacing`用于修改字间间隔

##### 字母间隔

`letter-spacing`和`word-spacing`唯一的区别就是字母间隔`letter-spacing`修改的是字符或字母之间的间隔


### 四. 文本转换

`text-transform`属性用于处理文本的大小写,默认值为`none`

其值为：

* uppercase 
* lowercase
* capitalize
* none
* inherit

### 五. 文本装饰

`text-decoration`是个很有意思的属性

其值为：

* none
* underline
* overline
* line-through
* inherit

`underline`会对元素加下划线，`overline`则对元素加上划线

`line-through`在文本中间画一条贯穿线

`none`值会关闭原本应用到一个元素上的所有装饰，比如想去掉超链接的下划线，就可以设置：

	a {text-decoration: none;}


### 六. 文本阴影

`text-shadow`用于定义元素的阴影

比如：
	
	p {text-shadow: green 5px 0.5em 2px;}

颜色后面的前两个值确定了阴影与文本的偏离距离（上述表示相对文本向右偏移5px向下偏移0.5em）

第三个长度值可选，定义了阴影的“模糊半径”


##### 处理空白符

`white-space`会影响用户代理对源文档中的空格、换行和tab字符的处理

这个属性感觉不常用，就不多介绍了