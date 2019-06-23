## vim
###

### 基本操作

#### 1. insert(插入)模式

从normal模式进入insert模式：

    i 在当前字符前插入
    a 在当前字符后插入
    o 在当前行的下一行插入新的一行
    I 在光标所在行的行首插入
    A 在光标所在行的行尾插入
    O 在当前行的上一行插入新的一行

#### 2. cmd(命令)模式

Normal模式下输入:之后执行命令，比如：

    :w 保存
    :q 退出
    :vs 垂直分屏
    :sp 水平分屏
    :% s/foo/bar/g 全局替换
    :set nu 设置行号
    ...
    
部分命令后面详细介绍...

#### 3. visual(可视)模式

visual模式一般用来块状选择文本：

    1) normal模式下使用v进入visual模式
    2) 使用V选择行
    3) 使用ctrl + v进行方块选择
    
选择完块状文本后可对其进行批量操作，比如将选中文本删除(选中后按d), 复制(选中后按y)等

#### 4. 快速纠错

    ctrl + h 删除上一个字符
    ctrl + w 删除上一个单词
    ctrl + u 删除当前行
    
上述几个快捷键可以用在很多地方，比如终端

#### 5. 快速切换insert和normal模式

    1) 使用ctrl + c或者ctrl + [代替ESC
    2) 使用gi快速跳转到最后一次编辑的地方并进入插入模式
    
    
#### 6. 快速移动

    h 左移
    j 下移
    k 上移
    l 右移
    
#### 7. 在单词间快速移动

    // 这里word是以非空白符分割的单词, WORD是以空白符分割的单词
    // w/W 和 e/E差不多
    // 一般使用w和b就够了
    w 移到下一个word开头
    W 移到下一个WORD开头
    e 移到下一个word尾
    E 移到下一个WORD尾
    b 回到上一个word开头
    B 回到上一个WORD开头
    
#### 8. 行间搜索移动

    1) 使用f+{char}可以移动到该行的char字符上,用分号(;)/逗号(,)继续搜索该行下一个/上一个char字符
    2) 使用F+{char}表示反过来搜前面的字符

#### 9. 水平移动

    0 移动到行首第一个字符
    $ 移动到行尾
    
#### 10. 页面移动

    gg 移动到文件开头
    G 移动到文件结尾
    H 跳转到屏幕的开头
    M 跳转到屏幕中间
    L 跳转到屏幕结尾
    ctrl + u 向上翻页
    ctrl + f 向下翻页
    
#### 11. 快速删除

    1. 在normal模式下使用x快速删除一个字符
    2. 使用d(delete)配合文本对象来快速删除，如daw(d around word), diw(相比daw不会删除word后的空格), dw(daw的缩写), dd(删除当前行), dt"(d till ", 删除直到"的所有内容)
    3. d和x都可以搭配数字来多次执行
    4. 可进入visual模式然后选中内容后用x或者d删除
   
#### 12. 快速修改

    // 常用的有三个
    r replace
    c change
    s substitute
    
    1. normal模式下使用r可以替换一个字符, 比如ra会把当前字符替换成a
    2. 而s会替换一个字符并进入insert模式(相比r多了进入insert模式)
    3. c配合文本对象可以快速进行修改, 和上述的d功能类似(相比d多了进入insert模式)
    
#### 13. 查询

    1. 使用/或者?进行前向或者反向搜索
    2. 使用n/N跳转到下一个或者上一个匹配
    3. 使用×或者#进行当前单词的前向和后向匹配
    
#### 14. 搜索替换

    // substitute命令允许我们查找并且替换掉文本，并且支持正则表达式
    :[range] s[ubsititute]/{pattern}/{string}/[flags]
    
    range表示范围, 比如:10, 20表示10-20行, :%表示全部
    
    pattern是要替换的模式, string是替换后文本
    
    flags有几个常用标志：
    1. g(global)表示全局范围内执行
    2. c(confirm)表示确认, 可以确认或者拒绝修改
    3. n(number)报告匹配到的次数而不替换, 可以用来查询匹配次数
 
    示例：
    :% s/self/this/g
    :1,6 s/self/this/g
    :1,6 s/self//n (查1-6行self出现次数)
    :% s/\<quack\>/xxx/g (精确匹配quack)
    
#### 15. 多文件操作

    多文件操作相关概念：
    Buffer是指打开的一个文件的内存缓冲区
    窗口是Buffer可视化的分割区域
    Tab可以组织窗口为一个工作区
    
    1. Buffer
    - Vim打开一个文件后会加载文件内容到缓冲区
    - 之后的修改都是针对内存中的缓冲区，并不会直接保存到文件
    - 直到执行:w才会把修改内容写入到文件
    - 打开多个文件就会有多个Buffer缓冲区
    
    Buffer切换
    - 使用:ls会列举当前缓冲区，然后使用:b n跳转到第n个缓冲区
    - :bpre :bnext :bfirst :blast
    - 或者用:b buffer_name 来跳转
    
    可使用:e 文件名 在当前窗口打开另一个文件Buffer !!!
    
    2. Window窗口
    - 一个缓冲区可以分割为多个窗口，每个窗口也可以打开不同的缓冲区
    - sp为水平分割，vs为垂直分割
    
    Windows窗口切换
    <ctrl-w>w 在窗口间循环切换
    <ctrl-w>h 切换到左边的窗口
    <ctrl-w>j 切换到下边的窗口
    <ctrl-w>k 切换到上边的窗口
    <ctrl-w>l 切换到右边的窗口
    
    3. Tab标签页
    Tab是可以容纳一系列窗口的容器
    - Vim的Tab和其他编辑器不太一样，可以想象成Linux的虚拟桌面
    - 比如一个Tab全用来编辑Python文件，另一个Tab全用来编辑HTML文件
    - 相比窗口，Tab使用较少，管理也较麻烦
    
    Tab操作（简单了解）
    :tabe[dit] {filename} 在新标签页打开filename
    :tabn[ext](同普通命令gt) 切换到下一标签页
    :tabp[revious](同普通命令gT) 切换到上一标签页
    
#### 16. Normal模式下复制粘贴

    1. normal模式下复制粘贴分别使用y(yank)和p(put)，剪贴为d和p
    2. 我们可以使用v(visual)命令选中要复制的地方，然后使用p粘贴
    3. 配合文本对象：比如yiw为复制一个单词，yy为复制一行
    4. vim中的剪贴(cut),复制(copy),粘贴(paste)对应为delete/yank/put