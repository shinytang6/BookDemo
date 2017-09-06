## 选择器
###

> 选择器是第二章最主要的部分，下面记录下我认为有收获的地方。

##### css声明规则有两个基本部分：选择器和声明块。
##### 声明块由一个或多个声明组成，每个声明则是一个属性-值对。

### 一. 元素选择器

最常见的选择器就是HTML元素

#### 选择器分组
	
就是可以为两个元素同时赋相同的值(用逗号分隔)

比如	
	
	h2, p {color: gray;}

#### 声明分组

就是可以为元素同时设置多个属性

比如

	h1 {font-size: 18px;color: purple;background:aqua;}

##### 要注意的是，对声明分组时，一定要在各个声明最后使用分号！

浏览器会忽略样式表中的空白符,对于：

	h1 {
	font-size: 18px;
	color: purple;
	background:aqua;
	}

如果忽略了第二个分号，用户代理就会把这个样式表解释为：

	h1 {
	font-size: 18px;
	color: purple  background:aqua;
	}

因为`background: `对于`color`来说不合法，所以第二个样式不会生效。

### 二. 类选择器和ID选择器

这个很好理解，就是通过声明HTML元素的`class`和`id`来获取。

#### 类选择器

	// 选择器会匹配class属性包含warning的所有元素
	.warning {font-weight: bold;}

	// 选择器会匹配class属性包含warning的所有p元素
	// 注意p和.warning之间没有空格！
	p.warning {font-weight: bold;}

#### 多类选择器

上面只说到了class中包含一个词的情况。

	// 第三行通过把两个类选择器链接在一起，
	// 可以选择同时包含这些类名的元素，
	// 即HTML源码中包含class="warning urgent"的元素
	.warning {font-weight: bold;}
	.urgent {font-style: italic;}
	.warning.urgent {background: silver;}

	// 同样，以下也合法
	p.warning.urgent {background: silver;}

#### ID选择器

	// 选择器会匹配id属性包含lead的所有元素
	#lead {font-weight: bold;}
	

### 三. 属性选择器

> 这一小节是我原先不了解的。

#### 简单属性选择

	// 选择有class属性（值不限）的所有h1元素，使其文本为银色
	h1[class] {color: silver;}

	// 选择所有带有alt属性的图像
	img[alt] {border: 3px solid red;}

	还可以根据多个属性进行选择，只需将属性选择器链接在一起即可。

	// 选择同时有href和title属性的HTML超链接，将其文本置为粗体
	a[href][title] {font-weight: bold;}

#### 根据具体属性值选择

除了选择有某些属性的元素，还可以进一步缩小选择范围，只选择有特定属性值的元素。

	// 选择href值为http://www.baidu.com而且title属性为W3C Home的所有HTML超链接
	a[href="http://www.baidu.com"][title="W3C Home"] {font-size: 200%}

	要注意的是，这种格式要求必须与属性值完全匹配！

	考虑以下片段：
	<p class="urgent warning">Test</p>
	// 要根据具体属性值来选择这个元素，必须写作：
	p[class="urgent warning"] {font-weight: bold;}
	// 上述属性值中必须urgent在前warning在后，而且有一个空格将其分隔

#### 根据部分属性值选择

	对于上述：
	<p class="urgent warning">Test</p>
	// 假设你想选择class属性中包含warning的元素，可以用一个属性选择器做到
	p[class~="warning"] {font-weight: bold;}
	// 波浪号正是部分选择的关键，即根据属性值中出现的一个用空格分隔的词来完成选择

除了波浪号（~），其他子串匹配属性选择器：

	[foo^="bar"]   选择foo属性值以"bar"开头的所有属性
	[foo$="bar"]   选择foo属性值以"bar"结尾的所有属性
	[foo*="bar"]   选择foo属性值中包含子串"bar"的所有属性


### 四. 特定属性选择类型

	// 这个规则会选择lang属性等于en或者以en-开头的所有元素
	*[lang|="en"] {color: white;}
	// 比如<h1 lang="en">Hello</h1>会被选中
	// <p lang="fr">Bonjour</p>不会被选中

这个属性后面还会介绍到，原文此处没有详细展开。

### 五. 使用文档结构

#### 后代选择器

	// 将作为h1元素后代的em元素的本文变成灰色
	// 注意两个元素之间要用空格隔开！记得与前文提到的不用空格隔开作对比！！！
	h1 em {color: gray;}
	
	// 当然并不仅限于两个选择器
	// 如：ul ol ul em {color: gray;}

#### 选择子元素

在某些情况下，可能并不像选择一个任意的后代元素，而是希望缩小范围，只选择另一个元素的子元素。

	// 将第一个h1下面出现的strong元素变成红色，但第二个出现的strong不受影响
	h1 > strong {color: red;}

#### 选择相邻兄弟元素

	// 选择紧接在一个h1元素后出现的p元素
	h1 + p {margin-top: 0;}

### 六. 伪类和伪元素

#### 伪类选择器

主要知识点为五个伪类：

	:link    超链接（即有href属性）点击前
	:visited  已访问地址的超链接
	:focus   当前拥有输入焦点的元素，一般多为input元素吧
	:hover  鼠标悬浮
	:active   鼠标点击时 

##### 这里要注意区分：

	// 第一条对所有a标签有效	
	// 第二条只对含有href属性的a标签有效
	a {color: blue;}
	a:link {color: blue;}


上述五个伪类最常用于超链接的上下文中。很多Web页面都有类似样式：

	// 虽然我这里自己也尝试了一下，:link设置单位属性并没正常显示，其他属性都正常，查了好久没找到原因
	a:link {color: navy;}
	a:visited {color: gray;}
	a:hover {color: red;}
	a:active {color: yellow;}

#####　注意：伪类的顺序很重要，通常建议是：link-visited-focus-hover-active。如果颠倒就会失效。

另外，还可以使用另一个静态伪类：`first-child`来选择元素的第一个子元素，我这里就不多写了。

#### 伪元素选择器

##### 设置首字母样式
		
	// 设置一个块级元素p首字母的样式
	p:first-letter {color: red;}

##### 设置第一行的样式

	// 可以影响元素中的第一个文本行
	p:first-line {color: purple;}

##### 设置之前和之后元素的样式

	// 设置一种排版效果，在每个h2元素前加一对银色中括号
	h2:before {content: "{{"; color: silver;}

	// 在文档最后加结束语
	body:after {content: " The End.";}

####### 感觉这个属性很厉害，在最近看的一个视频中也出现了！
	