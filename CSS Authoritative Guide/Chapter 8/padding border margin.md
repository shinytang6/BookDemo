## 内边距、边框和外边距
###

> 这一章简单地记录下重点，因为原先都有过接触。

### 一. 外边距

#### 值复制 

有时，为外边距输入的值会有些重复：

	p {margin: 0.25em 1em 0.25em 1em;}

不过，不必像这样重复地键入这对数字。不需要用上面的规则，你可以试试以下规则：

	p {margin: 0.25em 1em;}

这两个值足以取代前面的4个值。在CSS中定义了一些规则，允许为外边距指定少于4个值。规则如下：

* 如果缺少左外边距的值，则使用右外边距的值。
* 如果缺少下外边距的值，则使用上外边距的值。
* 如果缺少右外边距的值，则使用上外边距的值。

### 二. 边框

每个边框有3个方面：宽度或粗细、其样式或外观、以及其颜色。

边框宽度的默认值为`medium`,这个值没有明确定义。尽管如此，你不一定能看到边框，原因是边框的默认样式为`none`，这样一来，就不会有边框了。

##### 有样式的边框

CSS为属性`border-style`定义了10个不同的非`inherit`样式，包括默认值`none`

其值：

* none
* hidden
* dotted
* dashed
* solid
* double
* groove
* ridge
* inset
* outset
* inherit

可以为给定边框定义多个样式

	p {border-style: solid dashed dotted solid;}

单边样式：

* border-top-style
* border-right-style
* border-left-style
* border-bottom-style

##### 边框宽度

相关属性：

* border-width
* border-top-width
* border-right-width
* border-left-width
* border-bottom-width

其默认值为`medium`

这里讨论个问题：

如果`border-style`设置为none时会出现什么？

	p {border-style: none; border-width: 20px;}

尽管边框宽度为20px，但style设置为none。这种情况下由于边框不存在，所以它不可能有宽度，因此width自动设置为0，而不论你原先定义什么。

##### 边框颜色

相关属性：

* border-color
* border-top-color
* border-right-color
* border-left-color
* border-bottom-color

`border-color`有一个颜色值`transparent`（表示边框透明）。这个值用于创建有宽度的不可见边框。

##### 简写边框属性

相关属性：

* border
* border-top
* border-right
* border-left
* border-bottom


### 三. 内边距

相关属性：

* padding
* padding-top
* padding-right
* padding-left
* padding-bottom