## CSS中的Flex布局

> Flex 是 Flexible Box 的缩写，意为"弹性布局"

### 基本概念

采用 Flex 布局的元素，称为 Flex 容器（flex container），简称"容器"。

它的所有子元素自动成为容器成员，称为 Flex 项目（flex item），简称"项目"。

### 容器的属性

以下6个属性设置在容器上：

* flex-direction
* flex-wrap
* flex-flow
* justify-content
* align-items
* align-content

### 项目的属性

以下6个属性设置在项目上：

* order
* flex-grow
* flex-shrink
* flex-basis
* flex（flex-grow, flex-shrink 和 flex-basis的简写）
* align-self

##### 我这里只记录下一种最常用的布局方式：

如果所有项目的`flex-grow`属性都为1，则它们将等分剩余空间（如果有的话）。

如果一个项目的`flex-grow`属性为2，其他项目都为1，则前者占据的剩余空间将比其他项多一倍。

例如：

	容器 {display: flex;}
		项目 {flex:1;}
	

更详细的教程请参考：

[Flex 布局教程：语法篇](http://www.ruanyifeng.com/blog/2015/07/flex-grammar.html)

[Flex 布局教程：实例篇](http://www.ruanyifeng.com/blog/2015/07/flex-examples.html)