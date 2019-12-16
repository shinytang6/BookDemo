## Linux里source、sh、bash、./有什么区别
###

> 之前用习惯了这些命令，并没去关注他们的差别，这里简单记录下

### source

    source a.sh
    
在当前shell内去读取、执行a.sh，而a.sh不需要有"执行权限"

source命令可以简写为"."

    . a.sh
    
注意：中间是有空格的

### sh/bash

    sh a.sh
    bash a.sh
    
这两者都是打开一个subshell去读取、执行a.sh，而a.sh不需要有"执行权限"

通常在subshell里运行的脚本里设置变量，不会影响到父shell的

### ./

    ./a.sh
    #bash: ./a.sh: 权限不够
    chmod +x a.sh
    ./a.sh
    
打开一个subshell去读取、执行a.sh，但a.sh需要有"执行权限"

可以用chmod +x添加执行权限

### 另外再提一下 fork、source、exec之间的区别

1. 使用fork方式运行script时， 就是让shell(parent process)产生一个child process去执行该script，当child process结束后，会返回parent process，但parent process的环境是不会因child process的改变而改变的。
2. 使用source方式运行script时， 就是让script在当前process内执行， 而不是产生一个child process来执行。由于所有执行结果均于当前process内完成，若script的环境有所改变， 当然也会改变当前process环境了。
3. 使用exec方式运行script时， 它和source一样，也是让script在当前process内执行，但是process内的原代码剩下部分将被终止。同样，process内的环境随script改变而改变。

通常如果我们执行脚本时，比如命令`./a.sh`都是默认为fork的。


ref: 

1. [https://www.cnblogs.com/pcat/p/5467188.html](https://www.cnblogs.com/pcat/p/5467188.html)