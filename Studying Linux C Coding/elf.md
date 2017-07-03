## ELF文件及相关工具

#### 一. ELF文件是一个开放标准，各种UNIX系统的可执行文件都采用该格式，它有三种不同的类型：

1. 可重定位的目标文件

2. 可执行文件

3. 共享库

#### 二. 程序的汇编、链接、运行过程：

1. 写一个汇编程序保存成文本文件max.s

2. 汇编器读取文本转换成目标文件max.o,目标文件由若干个Section组成，我们在汇编程序中声明的.section会成为目标文件中的Section,此外汇编器还会自动添加一些Section(比如符号表)

3. 然后链接器把目标文件中的Section合并成几个Segment,生成可执行文件max

4. 最后加载器根据可执行文件中的Segment信息加载运行这个程序

#### 三.readelf工具

1. readelf工具可读出目标文件的 ELF Header 和 Section Header Table

		$ readelf -a xxx.o 或者 $ readelf -a xxx

2. ELF Header描述了体系结构和操作系统等基本信息，Section Header Table中保存了所有Section的描述信息，Program Header Table中保存了所有Segment的描述信息

3. 目标文件需要链接器做进一步处理，所以一定有Section Header Table;可执行文件需要加载运行，所以一定有Program Header Table;而共享库既要加载运行，又要加载时做动态链接，所以既有Section Header Table又有Program Header Table

#### 四.hexdump工具

hexdump工具可把目标文件的字节全部打印出来

		$ hexdump -C xxx.o

#### 五.objdump工具

objdump工具可以把程序中的机器指令反汇编

		$ objdump -d xxx.o 或者 $ objdump -d xxx