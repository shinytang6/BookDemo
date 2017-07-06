##  make工具自动化构建

#### 一.make工具
make编译的文件叫目标，对于目标，make需要知道两件事：

1. 依赖项

2. 生成方法


#### 二.makefile向make描述代码

通常做法是写一个Makefile文件和源代码放在同一个目录下

例如：

	main: main.o stack.o maze.o
    		gcc main.o stack.o maze.o -o main
    main.o: main.c main.h stack.h maze.h
    		gcc -c main.c
    stack.o: stack.c stack.h main.h
			gcc -c stack.c
	maze.o: maze.c maze.h main.h
			gcc -c maze.c

注：每个生成方法必须以tab开始，用空格不行

然后在这个目录下运行make编译
	
	$ make
	