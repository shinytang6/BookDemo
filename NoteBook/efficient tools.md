## efficient tools
###

> 记录一下我开发过程中能提升效率的各种工具

### 一. vim

> 最牛逼的文本编辑器= =

    简单记录下我常用的命令

    移动光标常用命令
    30↑  向上移动 30 行
    30↓  向下移动 30 行
    30←  向左移动 30 行
    30→  向右移动 30 行
    0 或功能键[Home]	 移动到这一行的最前面字符处
    $ 或功能键[End]   移动到这一行的最后面字符处
    G    移动到这个档案的最后一行
    nG   n 为数字。移动到这个档案的第 n 行。例如 20G 则会移动到这个档案的第 20 行(可配合 :set nu)
    gg   移动到这个档案的第一行，相当于 1G
    n<Enter>    n 为数字, 光标向下移动 n 行
    
    搜索替换常用命令
    /word  向光标之下寻找一个名称为 word 的字符串。例如要在档案内搜寻 vbird 这个字符串，就输入 /vbird 即可
    ?word  向光标之上寻找一个字符串名称为 word 的字符串
    n  这个 n 是英文按键。代表重复前一个搜寻的动作。举例来说， 如果刚刚我们执行 /vbird 去向下搜寻 vbird 这个字符串，则按下 n 后，会向下继续搜寻下一个名称为 vbird 的字符串。如果是执行 ?vbird 的话，那么按下 n 则会向上继续搜寻名称为 vbird 的字符串！
    N  这个 N 是英文按键。与 n 刚好相反，为『反向』进行前一个搜寻动作。 例如 /vbird 后，按下 N 则表示『向上』搜寻 vbird 。
    :n1,n2s/word1/word2/g  n1 与 n2 为数字。在第 n1 与 n2 行之间寻找 word1 这个字符串，并将该字符串取代为 word2 ！举例来说，在 100 到 200 行之间搜寻 vbird 并取代为 VBIRD 则： 『:100,200s/vbird/VBIRD/g』。

    删除、复制与粘贴常用命令
    x, X  在一行字当中，x 为向后删除一个字符 (相当于 [del] 按键)， X 为向前删除一个字符(相当于 [backspace] 亦即是退格键) 
    dd    删除游标所在的那一整行
    ndd   n 为数字。删除光标所在的向下 n 行，例如 20dd 则是删除 20 行
    yy    复制游标所在的那一行
    nyy   n 为数字。复制光标所在的向下 n 行，例如 20yy 则是复制 20 行
    p, P  p 为将已复制的数据在光标下一行贴上，P 则为贴在游标上一行！ 举例来说，我目前光标在第 20 行，且已经复制了 10 行数据。则按下 p 后， 那 10 行数据会贴在原本的 20 行之后，亦即由 21 行开始贴。但如果是按下 P 呢？ 那么原本的第 20 行会被推到变成 30 行。
    u     复原前一个动作
    [Ctrl]+r   重做上一个动作
    .     不要怀疑！这就是小数点！意思是重复前一个动作的意思。 如果你想要重复删除、重复贴上等等动作，按下小数点『.』就好了！
    
    vim 环境的变更
    :set nu    显示行号，设定之后，会在每一行的前缀显示该行的行号
    :set nonu  与 set nu 相反，为取消行号！
    
    
### 二. fzf

> A command-line fuzzy finder
> https://github.com/junegunn/fzf


### 三. ag

> A code-searching tool
> https://github.com/ggreer/the_silver_searcher

### 四. thefuck

> https://github.com/nvbn/thefuck

### 五. autojump


ref:

1. [http://www.runoob.com/linux/linux-vim.html](http://www.runoob.com/linux/linux-vim.html)
    