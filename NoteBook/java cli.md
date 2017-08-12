## Java中带package和不带package的编译方式
###

#### 一. 先记录一下安装Java的过程

1. 下载JDK

	在官网直接下载安装，安装JDK的时候也会安装JRE，一并安装就可以了

2. 配置环境变量

	我选择安装JDK的安装目录是 G:\JavaJDK

	在"环境变量"——>"系统变量"中设置3项属性，JAVA_HOME,PATH,CLASSPATH(大小写无所谓),若已存在则点击"编辑"，不存在则点击"新建"

	变量名：JAVA_HOME

	变量值：G:\JavaJDK      // 要根据自己的实际路径配置

	变量名：CLASSPATH

	变量值：.;%JAVA_HOME%\lib\dt.jar;%JAVA_HOME%\lib\tools.jar;         //别漏掉前面的"."！！！

	变量名：Path

	变量值：%JAVA_HOME%\bin;%JAVA_HOME%\jre\bin;

#### 二. 带package和不带package的编译方式(巨坑！！！)

>Java中带package的程序和不带package的程序编译的方式是不同的。


1. 不带package的程序

	建立个HelloWorld.java的文件，放入G:\,内容如下：

		public class HelloWorld
		{
		   public static void main(String args[])
		   //向屏幕上写字符串"HelloWorld!"
		    {
		      System.out.println("HelloWorld!");
		    }
		}

	1) 编译

		命令行下敲：
		G:
		javac HelloWorld.java
		注：此时G:\下将生成一个HelloWorld.class的文件

	2） 运行

		命令行下继续敲：
		java HelloWorld
		注：HelloWorld别加上.class后缀。 

2. 带package的程序

	一般按照包的层次来做或者使用eclipse生成的带包的文件，如何在命令行下编译运行呢？

	在G:\net\test下建立一个HelloWorld.java的文件，放入G:\,内容如下：
		
		package net.test;  //注意：这个第一行就是对包进行说明，其中net后面的点其实是目录的意思。
		public class HelloWorld
		{
		   public static void main(String args[])
		   //向屏幕上写字符串"HelloWorld!"
		    {
		      System.out.println("HelloWorld!");
		    }
		}
				
	1）编译

		命令行下敲：
		G:
		cd net/test
		javac HelloWorld.java
		注：此时G:\下将生成一个HelloWorld.class的文件