## 标准I/O库函数
#
### 一. 文件分为文本文件和二进制文件

源文件是文本文件，而目标文件、可执行文件和库文件都是二进制文件

### 二. fopen/fclose
#### 1. fopen

    #include <stdio.h>
    FILE *fopen(const char *path,const char *mode)
    返回值：成功返回文件指针，出错返回NULL并设置errno

path可以是相对路径也可以是绝对路径

mode表示打开方式是读还是写，一般有六种组合方法：

"r" 只读，文件必须已经存在

"w" 只写，如果文件不存在则创建，如果文件存在则把文件长度截断为0字节再重新写，也就是替换原来内容

"a" 只能在文件末尾添加数据，如果文件不存在则创建

"r+" 允许读和写，文件必须已存在

"w+" 允许读和写，如果文件不存在则创建，如果存在则把文件截断为0字节再重新写

"a+" 允许读和追加数据，如果文件不存在则创建

#### 2.fclose
fopen调用应该和fclose调用配对，打开文件操作完之后一定要记得关闭

### 三. stdin/stdout/stderr