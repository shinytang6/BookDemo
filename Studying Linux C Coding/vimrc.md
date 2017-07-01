## vim配置文件 —— .vimrc

"去掉讨厌的有关vi一致性模式，避免以前版本的一些bug和局限

``set nocompatible``

"显示行号

``set number``

"检测文件的类型

``filetype on ``

"记录历史的行数

``set history=1000 ``

"背景使用黑色

``set background=dark`` 

"语法高亮度显示

``syntax on ``

"下面两行在进行编写代码时，在格式对起上很有用；

"第一行，vim使用自动对起，也就是把当前行的对起格式应用到下一行；

"第二行，依据上面的对起格式，智能的选择对起方式，对于类似C语言编
"写上很有用

``set autoindent``

``set smartindent``

"第一行设置tab键为4个空格，第二行设置当行之间交错时使用4个空格

``set tabstop=4``

``set shiftwidth=4``

"设置匹配模式，类似当输入一个左括号时会匹配相应的那个右括号

``set showmatch``

"去除vim的GUI版本中的toolbar

``set guioptions=T``

"当vim进行编辑时，如果命令错误，会发出一个响声，该设置去掉响声

``set vb t_vb=``

"在编辑过程中，在右下角显示光标位置的状态行

``set ruler``

"默认情况下，寻找匹配是高亮度显示的，该设置关闭高亮显示

``set nohls``

"查询时非常方便，如要查找book单词，当输入到/b时，会自动找到第一
"个b开头的单词，当输入到/bo时，会自动找到第一个bo开头的单词，依
"次类推，进行查找时，使用此设置会快速找到答案，当你找要匹配的单词
"时，别忘记回车

``set incsearch``

"修改一个文件后，自动进行备份，备份的文件名为原文件名加"~"后缀

``if has("vms")`` //注意双引号要用半角的引号" "

``set nobackup``

``else``

``set backup``

``endif``