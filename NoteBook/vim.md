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
    
#### 16. normal模式下复制粘贴

    1. normal模式下复制粘贴分别使用y(yank)和p(put)，剪贴为d和p
    2. 我们可以使用v(visual)命令选中要复制的地方，然后使用p粘贴
    3. 配合文本对象：比如yiw为复制一个单词，yy为复制一行
    4. vim中的剪贴(cut),复制(copy),粘贴(paste)对应为delete/yank/put
    
#### 17. insert模式下复制粘贴

    通常会使用鼠标进行选中，然后使用ctrl+v或者cmd+v粘贴
    1. 这个和其他的文本编辑器差不多，但粘贴代码有坑，格式会乱
    2. 这个时候需要使用:set paste和:set nopaste解决
    
#### 18. vim的寄存器

    1. vim里操作的是寄存器而不是系统剪贴板，这和其他编辑器不同
    2. vim不使用单一剪贴板进行剪贴、复制与粘贴，而是多组寄存器
    3. 默认我们使用d删除或者y复制的内容都放到了“无名寄存器”
    4. 通过 "{register} 前缀可以指定寄存器，不指定默认用无名寄存器
    5. 比如使用 "ayiw 复制一个单词到寄存器a中， "bdd 删除当前行到寄存器b中
    
    可以通过:reg来查看vim寄存器情况！
    
    除了有名寄存器a-z之外，vim中还有一些其他常见寄存器
    1. 复制专用寄存器 "0 使用y复制文本同时会被拷到复制寄存器0
    2. 系统剪贴板 "+ 可以在复制前加上 "+ 复制到系统剪贴板(可用于从vim中复制到别的地方)
    
    ps: 可通过:echo has('clipboard')来查看是否支持系统剪贴板
    还可以设置:set clipboard=unnamed来直接复制粘贴系统剪贴板内容(就不需要在复制或者粘贴系统剪贴板内容时加 "+ 了)
    使用系统剪贴板可以替代频繁的:set paste/:set nopaste操作！设置了:set clipboard=unnamed则更方便！
    
#### 19. macro宏

    1. 宏可以堪称是一系列命令的集合
    2. 可以使用宏[录制]一系列操作，然后用于[回放]
    3. 宏可以非常方便地把一系列命令用在多行文本上
    
    宏的使用可分为录制和回放
    - vim使用q来录制，同时也是q结束录制
    - 使用q{register}选择要保存的寄存器，把录制的命令保存其中
    - 使用@{register}回放寄存器中保存的一系列命令
    
    如想要给多行加上双引号：
    1. 先给一行加上双引号，然后再回放到其他所有行
    2. 先使用q开始录制，给一行加上双引号，之后使用q退出
    3. 在剩下的所有行中回放录制的宏
    4. 可以在visual模式下输入:normal @{register}批量回放宏
    
#### 20. 代码补全

    <ctrl-n> 普通关键字，单词默认选中第一个
    <ctrl-p> 普通关键字，单词默认选中最后一个
    <ctrl-x><ctrl-f> 文件名补全
    <ctrl-x><ctrl-o> 全能补全(需要开启文件类型检查，安装插件)
    
#### 21. 更换配色

    1. 使用:colorscheme显示当前主题配色
    2. 使用:colorscheme <ctrl+d>可以显示所有配色
    3. 用:colorscheme 配色名就可以修改配色，当然也可以在vimrc中持久化配色
    
#### 22. 映射
    
    vim映射就是把一个操作映射到另一个操作
    
    以基本映射为例子，基本映射指的是normal模式下的映射，当然还有其他模式下的映射
    - 使用map就可以实现映射。比如:map - x 然后按-就会删除字符
    - :map <space> viw告诉vim按下空格时选中整个单词
    - :map <c-d> dd可以使用ctrl+d执行dd删除一行
    
    vim常用模式normal/visual/insert都可以定义映射
    - 用nmap/vmap/imap定义映射只在normal/visual/insert分别有效
    - :vmap \ U把在visual模式下选中的文本大小(u/U转换大小写)
    - :imap <c-d> <Esc>ddi 在insert模式下映射ctrl+d删除一行
    
    *map系列命令有递归的风险，解决方案就是使用非递归映射
    - 使用*map对应的noremap/nnoremap/vnoremap/inoremap
    - 任何时候都应该使用非递归映射，拯救自己和插件作者
    
#### 23. 插件

    安装插件步骤，我是使用vim-plug来管理插件
    1. 修改.vimrc文件，增加插件名称
    2. 重启vim，执行:PlugInstall

    好用插件列表：
    1. vim-startify: 一个好用的vim开屏插件，修改启动界面   
    2. lightline.vim: 状态栏美化(vim-airline功能类似，但我觉得没有lightline好看)
    3. indentline: 增加代码缩进线条
    4. vim-hybrid-material: 配色方案
    5. nerdtree: 文件目录树管理
        - 映射了<,>+v 查找文件位置(可快速从别的窗口切回nerdtree)
        - 映射了<,>+g 打开/关闭nerdtree
    6. ctrlp: 快速搜索文件名并打开文件(文件搜索)
        - 模糊搜索器
        - 映射了<ctrl>+p触发ctrlp
        - 使用<ctrl>+p查找到文件后使用<,>+v可快速定位到文件位置
    7. easymotion: 快速跳转到当前窗口任意位置
        - 也可以使用vim的搜索/加上n跳转，但是使用easymotion更方便
        - 映射了ss根据需求跳转
    8. fzf.vim: 模糊搜索文本
        - 使用Ag [PATTERN]模糊搜索字符串
        - 使用Files [PATH]模糊搜索目录(和ctrlp类似)
    9. vim-go
        - Go代码补全，重构，跳转，自动格式化，自动导入
    10. python-mode
        - Python代码补全，重构，跳转，自动格式化，自动导入
    11. vim-interestingwords: 高亮感兴趣的单词，对浏览代码有用
        - <,>+k高亮单词
        - <,>+K清除所有单词高亮