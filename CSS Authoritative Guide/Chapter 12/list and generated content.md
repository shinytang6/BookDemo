## 列表与生成内容
###

### 一. 列表

在无序列表中，列表项的标志是出现在各列表项旁边的圆点；在有序列表中，标志可能是一个字母、数字或另外某种计数体系中的符号，甚至可以替换为图像。

##### 列表类型

要修改用于列表项的标志类型，可以使用属性`list-style-type`

值：

* disc   使用实心圆作为列表项标志
* circle   使用一个空心圆作为列表项标志
* square   使用一个方块作为列表项标志
* decimcal   1,2,3,4,5,...
* upper-alpha   A,B,C,D,...
* lower-roman	i,ii,iii,iv,v,...
* none   不使用标志
* ...

初始值：`disc`

应用于：display值为list-item的元素

##### 列表项图像

有时，常规的标志还不够。你可能想对各标志使用一个图像，可以使用属性`list-style-image`

值：

* 相对应的uri
* none
* inherit

示例如下：

	ul li {list-style-image: url(xxx.gif);}

##### 列表标志位置

还可以做一件事来影响列表项的外观，即确定标志出现在列表项内容之外还是在内容内部，可以利用`list-style-position`

值：

* inside
* outside
* inherit

初始值：`outside`

应用于：display值为list-item的元素

##### 简写列表样式

属性：`list-style`

值： `list-style-type` | `list-style-image` | `list-style-position`

### 二. 生成内容

生成内容是指浏览器创建的内容，而不是由标志或内容来表示

##### 插入生成内容

为了向文档中插入生成内容，可以使用`:before`和`:after`伪元素

这些伪元素会根据`content`属性把生成内容放在一个元素内容的前面或后面

如：

	a[href]:before {content: "(link) ";}
	a.pdf-doc:after {content: url(pdf-dov-icon.gif);}

##### 指定内容

要生成内容，需要有一种办法来描述生成的内容。正如前面所看到，就是利用`content`属性

值：

* 字符串 
* uri
* attr()
* open-quote
* close-quote
* ...

###### 插入属性值

	// 把每个链接额href属性值直接放在链接的后面
	a[href]:after {content: attr(href);}
	// 上述还可以向声明增加一些串值(注意字符串间没有加号)
	a[href]:after {content: " [" attr(href) "]";}

##### 计数器

我们都已经对计数器很熟悉了，例如，有序列表中的列表项标志就是计数器

创建计数器的基础包括两个方面，一是能设置计数器的起点，二是能将其递增一定的量

###### 重置

属性：`counter-reset`

值：标识符（自己随便定义）

默认计数器重置为0

如：

	// 计数器chapter在重置时定义
	h1 {counter-reset: chapter;}
	// 默认地，计数器重置为0，如果想重置为另一个数，可以在标识符后面声明这个数
	h1 {counter-reset: chapter 4;}

###### 递增

属性：`counter-increment`

值：标识符（上述`counter-reset`中定义的值）+ 数字（默认为1）

如：

	// 一次递增2
	body{
	counter-reset: section;
	}
	h1 {
	counter-increment: section 2;
	}

不过，要具体显示计数器，还需要结合使用`content`属性和一个与计数器有关的值`counter`

如：

	body{
	counter-reset: section;
	}
	h1:before {
	counter-increment: section;
	content: counter(section);
	}
	
还可以为每个计数器定义一个列表样式，作为`counter()`格式的一部分，为此可以在计数器的标识符后面增加一个`list-style-type`关键字，用逗号分隔

如：

	body{
	counter-reset: section;
	}
	h1:before {
	counter-increment: section;
	content: counter(section,upper-alpha);
	}