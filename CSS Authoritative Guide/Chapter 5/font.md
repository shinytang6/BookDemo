## 字体
###

### 一. 字体系列

#### font-size

#### 通用字体系列

比如：

* Serif字体
* Sans-serif字体
* Monospace字体
* Cursive字体
* Fantasy字体

	body {font-family: serif;}

#### 指定字体系列

上述通用字体系列每种都包含许多特定字体种类

所以声明时也可以指定某一种特定字体

	h1 {font-family: Georgia;}

##### 注意：

1. 如果在`font-family`中声明多种字体，要用逗号分隔

		p {font-family: Times, serif;}		

2. 当一个字体名中有一个或多个空格（如New York）,或者如果字体名包含#或$之类的符号，要将字体名用引号包括

		p {font-family: Times, 'Karrank%', serif;}

### 二. 字体加粗

#### font-weight

### 三. 字体大小

#### font-size

### 四. 风格和变形

#### 有风格的字体：font-style

具体值：

* italic
* oblique
* normal
* inherit

##### italic和oblique其实在浏览器上一样，都是斜体效果

#### 字体变形：font-variant

具体值：

* small-caps
* normal
* inherit

##### small-caps的效果就是原来文本中的大写字母更大，原来的小写字母变为大写字母

### 五. font属性

> 这个知识点原来不太了解，重点记录下

##### font属性是涵盖所有其他字体属性（以及少数其他内容）的一个简写属性

规则：

* font的前三个属性为`font-style`,`font-weight`,`font-variant`,这三个属性允许采用任意的顺序，且是可选
* 后两个值则要严格的多，`font-size`和`font-family`不仅要以此顺序（font-size在前，font-family在后）作为声明中的最后两个值，而且font声明中必须有这两个值（如果少了其中的某个属性，那么整个规则都是无效的）

因此有如下结果：

	h1 {font: normal normal italic 30px sans-serif;}   // 正确
	h2 {font: 1.5em sans-serif;}   // 正确
	h3 {font: sans-serif}   // 错误，缺少font-size
	h4 {font: lighter 14px;}    // 错误，缺少font-family

	

