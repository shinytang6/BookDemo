## 调试工具——gdb
#### 一.单步执行和跟踪函数调用
1. 编译时要加上-g选项，生成的可执行文件才能用gdb进行源码调试。

	``$ gcc -g xx.c -o xx``
    
    ``$ gdb xx``
2. list命令列出源码，一次只列10行

    list命令简写为l,可用 ``(gdb) l 函数名``列出函数源代码
3.  start命令开始执行程序
   
    ``(gdb) start``

    用next(简写为n)控制语句一条一条执行

4. 用step命令（简写为s）钻入函数中去跟踪执行
   
    如对于下一条语句中含有函数调用，则可用s命令进入调用函数进行跟踪
    
    输入s命令后就停在了函数中变量定义之后的第一条语句之后。在函数中有几种查看状态的方法

    backtrace(bt) 查看函数调用栈帧：
    
    ``(gdb) bt``



    
    info(i) 查看函数局部变量的值：   

    ``(gdb) i locals``

    frame(f) 选择1号栈帧查看局部变量(这在输入s进入调用函数后才会用到)：

    ``(gdb) f 1``
    
    print(p) 打印出变量的值:
    
    ``(gdb) p xx``

    finish 让程序一直运行到从当前函数返回:
   
    ``(gdb) finish``

5. 找到错误可以退出gdb修改源码，或者直接在gdb中修改变量

    ``(gdb) set var xx = xx``


6. 用quit命令(简写为q)退出gdb调试环境
   
    ``(gdb) quit``   
    
    
#### 二.断点

1. display命令使得每次停下来都显示变量的值，然后继续往下走

    ``(gdb) display xx``

    也可以根据变量的编号undisplay

2. break(b)命令设置断点
   
     ``(gdb) b 9``	表示在第九行设置断点（可先用list命令列出源码）

     ``(gdb) b 函数名`` 表示在某个函数开头设置断点

     ``(gdb) b 9 if sum != 0`` 表示仅当sum!=0才在第九行中断
   
3. continue(c)命令连续运行而非单步运行，程序到达断点会停下来

4. info(i)命令还可以查看设置的断点

    ``(gdb) i breakpoints``

5. delete命令删除断点

    ``(gdb) delete breakpoints 数字`` 删除某个断点
    
    ``(gdb) delete breakpoints`` 删除所有断点

6. disable breakpoints 断点号 禁用断点

7. enable 断点号 启用断点

8. run(r) 从头开始连续运行程序

#### 三.观察点

1. watch命令设置观察点

    断点是当程序执行到某一行代码行中断，而观察点是当程序访问某个存储单元时中断，如果我们不知道某个存储单元是哪里被改动的，这时候观察点就很有用了

    ``(gdb) watch input[5]``
    ``(gdb) c``

     就会显示input[5]被改动的信息

2. info(i)命令还可以查看设置的观察点

    ``(gdb) i watchpoints``

3. x命令从某个位置开始打印存储单元的内容

    ``(gdb) x/7b input``

    ``0xbfb8f0af: 0x31 0x32 0x33 0x34 0x35 0x00 0x00``

    7b是打印格式，b表示每个字节一组，7表示打印7组，从input数组第一个字节起连续打印7个字节。(这里的例子input为字符数组)