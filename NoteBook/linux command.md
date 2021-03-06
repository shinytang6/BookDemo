## 1. less 

> less 工具也是对文件或其它输出进行分页显示的工具，应该说是linux正统查看文件内容的工具，功能极其强大。less 的用法比起 more 更加的有弹性。

> 在 more 的时候，我们并没有办法向前面翻， 只能往后面看，但若使用了 less 时，就可以使用 [pageup] [pagedown] 等按键的功能来往前往后翻看文件，更容易用来查看一个文件的内容！除此之外，在 less 里头可以拥有更多的搜索功能，不止可以向下搜，也可以向上搜。

#### 格式
	
	less [参数] 文件


#### 例子

1. ps查看进程信息并通过less分页显示

		ps -ef |less

2. 查看命令历史使用记录并通过less分页显示

		history | less


## 2. head

> head 用来显示档案的开头至标准输出中， head 用来显示档案的开头至标准输出中，默认head命令打印其相应文件的开头10行。


#### 格式

	head [参数]… [文件]…

#### 例子

1. 显示文件的前n行

		head -n 5 log2014.log


## 3. tail

> tail 命令从指定点开始将文件写到标准输出.使用tail命令的-f选项可以方便的查阅正在改变的日志文件,tail -f filename会把filename里最尾部的内容显示在屏幕上,并且不但刷新,使你看到最新的文件内容 

#### 格式

	tail[必要参数][选择参数][文件]

#### 例子

1. 显示文件末尾内容

		tail -n 5 log2014.log

2. 循环查看文件内容

		ping baidu.com > test.log & //在后台ping远程主机。并输出文件到test.log

		tail -f test.log // 循环查看文件内容


------

**我们经常在linux要查找某个文件，但不知道放在哪里了，可以使用下面的一些命令来搜索：**

**which 查看可执行文件的位置**

**whereis 查看文件的位置**

**locate 配合数据库查看文件位置**

**find 实际搜寻硬盘查询文件名称**

## 4. which

> which命令的作用是，在PATH变量指定的路径中，搜索某个系统命令的位置，并且返回第一个搜索结果。也就是说，使用which命令，就可以看到某个系统命令是否存在，以及执行的到底是哪一个位置的命令。

#### 格式

	which 可执行文件名称

#### 例子

1. 查找文件、显示命令路径

		which pwd

## 5. whereis

> whereis命令只能用于程序名的搜索，而且只搜索二进制文件（参数-b）、man说明文件（参数-m）和源代码文件（参数-s）。如果省略参数，则返回所有信息。

> 和find相比，whereis查找的速度非常快，这是因为linux系统会将 系统内的所有文件都记录在一个数据库文件中，当使用whereis和下面即将介绍的locate时，会从数据库中查找数据，而不是像find命令那样，通 过遍历硬盘来查找，效率自然会很高。

> 但是该数据库文件并不是实时更新，默认情况下时一星期更新一次，因此，我们在用whereis和locate 查找文件时，有时会找到已经被删除的数据，或者刚刚建立文件，却无法查找到，原因就是因为数据库文件没有被更新。

## 6. locate 

> locate 让使用者可以很快速的搜寻档案系统内是否有指定的档案。其方法是先建立一个包括系统内所有档案名称及路径的数据库，之后当寻找时就只需查询这个数据库，而不必实际深入档案系统之中了。在一般的 distribution 之中，数据库的建立都被放在 crontab 中自动执行。

#### 格式

	Locate [选择参数] [样式]

#### 例子

1. 查找和pwd相关的所有文件

		locate pwd

2. 搜索etc目录下所有以sh开头的文件

		locate /etc/sh


## 7. find

> Linux下find命令在目录结构中搜索文件，并执行指定的操作。Linux下find命令提供了相当多的查找条件，功能很强大。由于find具有强大的功能，所以它的选项也很多，其中大部分选项都值得我们花时间来了解一下。即使系统中含有网络文件系统( NFS)，find命令在该文件系统中同样有效，只你具有相应的权限。 在运行一个非常消耗资源的find命令时，很多人都倾向于把它放在后台执行，因为遍历一个大的文件系统可能会花费很长的时间(这里是指30G字节以上的文件系统)。


#### 格式

	find pathname -options [-print -exec -ok …] 

	pathname: find命令所查找的目录路径。例如用.来表示当前目录，用/来表示系统根目录。 
	-print： find命令将匹配的文件输出到标准输出。 
	-exec： find命令对匹配的文件执行该参数所给出的shell命令。相应命令的形式为’command’ { } ;，注意{ }和；之间的空格。 
	-ok： 和-exec的作用相同，只不过以一种更为安全的模式来执行该参数所给出的shell命令，在执行每一个命令之前，都会给出提示，让用户来确定是否执行。

#### 命令选项

	-name 按照文件名查找文件。 
	-perm 按照文件权限来查找文件。 
	-prune 使用这一选项可以使find命令不在当前指定的目录中查找，如果同时使用-depth选项，那么-prune将被find命令忽略。 
	-user 按照文件属主来查找文件。 
	-group 按照文件所属的组来查找文件。 
	-mtime -n +n 按照文件的更改时间来查找文件， - n表示文件更改时间距现在n天以内，+ n表示文件更改时间距现在n天以前。find命令还有-atime和-ctime 选项，但它们都和-m time选项。 
	-nogroup 查找无有效所属组的文件，即该文件所属的组在/etc/groups中不存在。 
	-nouser 查找无有效属主的文件，即该文件的属主在/etc/passwd中不存在。 
	-newer file1 ! file2 查找更改时间比文件file1新但比文件file2旧的文件。 
	-type 查找某一类型的文件，诸如： 
	b - 块设备文件。 
	d - 目录。 
	c - 字符设备文件。 
	p - 管道文件。 
	l - 符号链接文件。 
	f - 普通文件。 
	-size n：[c] 查找文件长度为n块的文件，带有c时表示文件长度以字节计。-depth：在查找文件时，首先查找当前目录中的文件，然后再在其子目录中查找。 
	-fstype：查找位于某一类型文件系统中的文件，这些文件系统类型通常可以在配置文件/etc/fstab中找到，该配置文件中包含了本系统中有关文件系统的信息。 
	-mount：在查找文件时不跨越文件系统mount点。 
	-follow：如果find命令遇到符号链接文件，就跟踪至链接所指向的文件。 
	-cpio：对匹配的文件使用cpio命令，将这些文件备份到磁带设备中。

	-amin n 查找系统中最后N分钟访问的文件 
	-atime n 查找系统中最后n*24小时访问的文件 
	-cmin n 查找系统中最后N分钟被改变文件状态的文件 
	-ctime n 查找系统中最后n*24小时被改变文件状态的文件 
	-mmin n 查找系统中最后N分钟被改变文件数据的文件 
	-mtime n 查找系统中最后n*24小时被改变文件数据的文件

#### 例子

1. 查找48小时内修改过的文件

		find -atime -2

2. 在当前目录查找 以.log结尾的文件。 “. “代表当前目录

		find . -name “*.log” 

3. 查找/opt/soft/test/目录下 权限为 777的文件

		find /opt/soft/test/ -perm 777 

4. 查找当前目录，以.log结尾的普通文件

		find . -type f -name “*.log” 

5. 查找当前所有目录并排序

		find . -type d | sort 

6. 查找当前目录大于1K的文件

		find . -size +1000c -print 

## 8. find命令之exec

> find是我们很常用的一个Linux命令，但是我们一般查找出来的并不仅仅是看看而已，还会有进一步的操作，这个时候exec的作用就显现出来了。

> exec解释：

> -exec 参数后面跟的是command命令，它的终止是以;为结束标志的，所以这句命令后面的分号是不可缺少的，考虑到各个系统中分号会有不同的意义，所以前面加反斜杠。

> {} 花括号代表前面find查找出来的文件名。

> 使用find时，只要把想要的操作写在一个文件里，就可以用exec来配合find查找，很方便的。在有些操作系统中只允许-exec选项执行诸如l s或ls -l这样的命令。大多数用户使用这一选项是为了查找旧文件并删除它们。建议在真正执行rm命令删除文件之前，最好先用ls命令看一下，确认它们是所要删除的文件。 

> exec选项后面跟随着所要执行的命令或脚本，然后是一对儿{ }，一个空格和一个\，最后是一个分号。为了使用exec选项，必须要同时使用print选项。如果验证一下find命令，会发现该命令只输出从当前路径起的相对路径及文件名。

#### 例子

1. 匹配到了当前目录下的所有普通文件，并在-exec选项中使用ls -l命令将它们列出

		find . -type f -exec ls -l {} \;

2. 在目录中查找更改时间在n日以前的文件并删除它们

		find . -type f -mtime +14 -exec rm {} \;

3. 在目录中查找更改时间在n日以前的文件并删除它们，在删除之前先给出提示

		find . -name “*.log” -mtime +5 -ok rm {} \;

4. find命令首先匹配所有文件名为“ passwd*”的文件，例如passwd、passwd.old、passwd.bak，然后执行grep命令看看在这些文件中是否存在一个root用户

		find /etc -name “passwd*” -exec grep “root” {} \; 

5. 查找文件移动到指定目录

		find . -name “*.log” -exec mv {} .. \;

6. 用exec选项执行cp命令

		find . -name “*.log” -exec cp {} test3 \;


## 9. find命令之xargs

> 在使用 find命令的-exec选项处理匹配到的文件时， find命令将所有匹配到的文件一起传递给exec执行。但有些系统对能够传递给exec的命令长度有限制，这样在find命令运行几分钟之后，就会出现溢出错误。错误信息通常是“参数列太长”或“参数列溢出”。这就是xargs命令的用处所在，特别是与find命令一起使用。

> find命令把匹配到的文件传递给xargs命令，而xargs命令每次只获取一部分文件而不是全部，不像-exec选项那样。这样它可以先处理最先获取的一部分文件，然后是下一批，并如此继续下去。

> 在有些系统中，使用-exec选项会为处理每一个匹配到的文件而发起一个相应的进程，并非将匹配到的文件全部作为参数一次执行；这样在有些情况下就会出现进程过多，系统性能下降的问题，因而效率不高； 而使用xargs命令则只有一个进程。另外，在使用xargs命令时，究竟是一次获取所有的参数，还是分批取得参数，以及每一次获取参数的数目都会根据该命令的选项及系统内核中相应的可调参数来确定。

#### 例子

1. 查找系统中的每一个普通文件，然后使用xargs命令来测试它们分别属于哪类文件

		find . -type f -print | xargs file

2. 在当前目录下查找所有用户具有读、写和执行权限的文件，并收回相应的写权限

		find . -perm -7 -print | xargs chmod o-w

3. 用grep命令在所有的普通文件中搜索hostname这个词

		find . -type f -print | xargs grep “hostname”

## 10. chmod 

> chmod命令用于改变linux系统文件或目录的访问权限。用它控制文件或目录的访问权限。该命令有两种用法。一种是包含字母和操作符表达式的文字设定法；另一种是包含数字的数字设定法。

> Linux系统中的每个文件和目录都有访问许可权限，用它来确定谁可以通过何种方式对文件和目录进行访问和操作。

> 文件或目录的访问权限分为只读，只写和可执行三种。以文件为例，只读权限表示只允许读其内容，而禁止对其做任何的更改操作。可执行权限表示允许将该文件作为一个程序执行。文件被创建时，文件所有者自动拥有对该文件的读、写和可执行权限，以便于对文件的阅读和修改。用户也可根据需要把访问权限设置为需要的任何组合。

> 有三种不同类型的用户可对文件或目录进行访问：文件所有者，同组用户、其他用户。所有者一般是文件的创建者。所有者可以允许同组用户有权访问文件，还可以将文件的访问权限赋予系统中的其他用户。在这种情况下，系统中每一位用户都能访问该用户拥有的文件或目录。

#### 格式

	chmod [-cfvR] [–help] [–version] mode file

#### 必要参数

	-c 当发生改变时，报告处理信息 
	-f 错误信息不输出 
	-R 处理指定目录以及其子目录下的所有文件 
	-v 运行时显示详细处理信息

	权限范围：
	u ：目录或者文件的当前的用户 
	g ：目录或者文件的当前的群组 
	o ：除了目录或者文件的当前用户或群组之外的用户或者群组 
	a ：所有的用户及群组

	权限代号：
	r ：读权限，用数字4表示 
	w ：写权限，用数字2表示 
	x ：执行权限，用数字1表示 
	- ：删除权限，用数字0表示 
	s ：特殊权限


该命令有两种用法。一种是包含字母和操作符表达式的文字设定法；另一种是包含数字的数字设定法。

1）. 文字设定法:

	chmod ［who］ ［+ | - | =］ ［mode］ 文件名

2）. 数字设定法

我们必须首先了解用数字表示的属性的含义：0表示没有权限，1表示可执行权限，2表示可写权限，4表示可读权限，然后将其相加。所以数字属性的格式应为3个从0到7的八进制数，其顺序是（u）（g）（o）。

例如，如果想让某个文件的属主有“读/写”二种权限，需要把4（可读）+2（可写）＝6（读/写）。

数字设定法的一般形式为：

	chmod ［mode］ 文件名

数字与字符对应关系如下：

r=4，w=2，x=1 
若要rwx属性则4+2+1=7 
若要rw-属性则4+2=6； 
若要r-x属性则4+1=7。


#### 例子

1. 增加文件所有用户组可执行权限

		// 即设定文件log2012.log的属性为：文件属主（u） 增加执行权限；与文件属主同组用户（g） 增加执行权限；其他用户（o） 增加执行权限。
		chmod a+x log2012.log

2. 同时修改不同用户权限

		// 即设定文件text的属性为：文件属主（u） 增加写权限;与文件属主同组用户（g） 增加写权限;其他用户（o） 删除执行权限
		chmod ug+w,o-x log2012.log

3. 删除文件权限

		// 删除所有用户的可执行权限
		chmod a-x log2012.log

4. 使用“=”设置权限

		// 撤销原来所有的权限，然后使拥有者具有可读权限
		chmod u=x log2012.log

5. 对一个目录及其子目录所有文件添加权限(不加-R对某个目录下面的子文件或目录不起作用)

		// 递归地给test4目录下所有文件和子目录的属主分配权限
		chmod -R u+x test4

6. 其他一些实例

		// 给file的属主分配读、写、执行(7)的权限，给file的所在组分配读、执行(5)的权限，给其他用户分配执行(1)的权限
		chmod 751 file

		// 与chmod 751 file等价
		chmod u=rwx,g=rx,o=x file

		// 为所有用户分配读权限
		chmod =r file

		// 与chmod =r file等价
		chmod 444 file


## 11. tar

> ar最初被用来在磁带上创建档案，现在，用户可以在任何设备上创建档案。利用tar命令，可以把一大堆的文件和目录全部打包成一个文件，这对于备份文件或将几个文件组合成为一个文件以便于网络传输是非常有用的。

> 首先要弄清两个概念：打包和压缩。打包是指将一大堆文件或目录变成一个总的文件；压缩则是将一个大的文件通过一些压缩算法变成一个小文件。

> 为什么要区分这两个概念呢？这源于Linux中很多压缩程序只能针对一个文件进行压缩，这样当你想要压缩一大堆文件时，你得先将这一大堆文件先打成一个包（tar命令），然后再用压缩程序进行压缩（gzip bzip2命令）。

> linux下最常用的打包程序就是tar了，使用tar程序打出来的包我们常称为tar包，tar包文件的命令通常都是以.tar结尾的。生成tar包后，就可以用其它的程序来进行压缩。

#### 格式

	tar[必要参数][选择参数][文件]


#### 例子

1. 仅打包，不压缩！ 

		tar -cvf log.tar log2012.log

2. 打包后，以 gzip 压缩 

		tar -zcvf log.tar.gz log2012.log

3. 打包后，以 bzip2 压缩

		tar -jcvf log.tar.bz2 log2012.log

> 在参数 f 之后的文件档名是自己取的，我们习惯上都用 .tar 来作为辨识。 如果加 z 参数，则以 .tar.gz 或 .tgz 来代表 gzip 压缩过的 tar包； 如果加 j 参数，则以 .tar.bz2 来作为tar包名。


4. 将tar 包解压缩

		tar -zxvf /opt/soft/test/log.tar.gz

5. 将下载的源码包解压至 /usr/local目录

		tar -C /usr/local -xzf xx.tar.gz


## 12. chgrp

> 在linux系统里，文件或目录的权限由拥有者及所属群组来管理。可以使用chgrp指令去变更文件与目录所属群组，这种方式采用群组名称或群组识别码都可以。Chgrp命令就是change group的缩写！要被改变的组名必须要在/etc/group文件内存在才行。

#### 格式

	chgrp [选项] [组] [文件]

#### 例子

1. 将log2012.log文件由root群组改为bin群组

		chgrp -v bin log2012.log

2. 改变指定目录以及其子目录下的所有文件的群组属性

		chgrp -R bin test6


## 13. chown

> chown将指定文件的拥有者改为指定的用户或组，用户可以是用户名或者用户ID；组可以是组名或者组ID；文件是以空格分开的要改变权限的文件列表，支持通配符。系统管理员经常使用chown命令，在将文件拷贝到另一个用户的名录下之后，让用户拥有使用该文件的权限

#### 格式

	chown [选项]… [所有者][:[组]] 文件… 

#### 例子

1. 改变拥有者和群组

		chown mail:mail log2012.log 

2. 改变文件群组

		chown :mail log2012.log

3. 改变指定目录以及其子目录下的所有文件的拥有者和群组

		chown -R -v root:mail test6 

## 14. /etc/group文件详解

> Linux /etc/group /etc/passwd和/etc/shadow文件都是有关于系统管理员对用户和用户组管理时相关的文件。linux /etc/group文件是有关于系统管理员对用户和用户组管理的文件,linux用户组的所有信息都存放在/etc/group文件中。具有某种共同特征的用户集合起来就是用户组（Group）。用户组（Group）配置文件主要有 /etc/group和/etc/gshadow，其中/etc/gshadow是/etc/group的加密信息文件。

> 将用户分组是Linux系统中对用户进行管理及控制访问权限的一种手段。**每个用户都属于某个用户组；一个组中可以有多个用户，一个用户也可以属于不 同的组。** 当一个用户同时是多个组中的成员时，在/etc/passwd文件中记录的是用户所属的主组，也就是登录时所属的默认组，而其他组称为附加组。

#### 格式

用户组的所有信息都存放在/etc/group文件中。此文件的格式是由冒号(:)隔开若干个字段，这些字段具体如下：

	组名:口令:组标识号:组内用户列表

具体解释：

	组名：组名是用户组的名称，由字母或数字构成。与/etc/passwd中的登录名一样，组名不应重复。

	口令：口令字段存放的是用户组加密后的口令字。一般Linux系统的用户组都没有口令，即这个字段一般为空，或者是*。

	组标识号：组标识号与用户标识号类似，也是一个整数，被系统内部用来标识组。别称GID.

	组内用户列表：是属于这个组的所有用户的列表，不同用户之间用逗号(,)分隔。这个用户组可能是用户的主组，也可能是附加组。

#### 例子

1. cat /etc/group

		[root@localhost test6]# cat /etc/group 
		root:x:0:root,linuxsir 
		bin:x:1:root,bin,daemon 
		daemon:x:2:root,bin,daemon 
		sys:x:3:root,bin

		
说明：

我们以`root:x:0:root,linuxsir` 为例： 

用户组root，x是密码段，表示没有设置密码，GID是0,root用户组下包括root、linuxsir以及GID为0的其它用户。


## 15. gzip

> 减少文件大小有两个明显的好处，一是可以减少存储空间，二是通过网络传输文件时，可以减少传输的时间。gzip是在Linux系统中经常使用的一个对文件进行压缩和解压缩的命令，既方便又好用。gzip不仅可以用来压缩大的、较少使用的文件以节省磁盘空间，还可以和tar命令一起构成Linux操作系统中比较流行的压缩文件格式。据统计，gzip命令对文本文件有60%～70%的压缩率。

#### 格式

	gzip[参数][文件或者目录]

#### 例子

1. 把目录下的每个文件压缩成.gz文件

		gzip *

2. 详细显示每个压缩文件的信息，并不解压

		gzip -l *

3. 把每个压缩的文件解压，并列出详细的信息

		gzip -dv *

4. 递归的压缩目录

		gzip -rv 目录名

5. 递归地解压目录

		gzip -dr 目录名

6. 压缩单个文件

		gzip 文件名

7. 解压单个文件

		gzip -d 文件名


## 16. date

> date 可以用来显示或设定系统的日期与时间。

## 17. cal

> 用于查看日历等时间信息，如只有一个参数，则表示年份(1-9999)，如有两个参数，则表示月份和年份

#### 例子

1. 显示当前月份日历

		cal

2. 显示指定月份的日历

		cal 9 2012	

## 18. grep

> Linux系统中grep命令是一种强大的文本搜索工具，它能使用正则表达式搜索文本，并把匹 配的行打印出来。grep全称是Global Regular Expression Print，表示全局正则表达式版本，它的使用权限是所有用户。

> grep的工作方式是这样的，它在一个或多个文件中搜索字符串模板。如果模板包括空格，则必须被引用，模板后的所有字符串被看作文件名。搜索的结果被送到标准输出，不影响原文件内容。

> grep可用于shell脚本，因为grep通过返回一个状态值来说明搜索的状态，如果模板搜索成功，则返回0，如果搜索不成功，则返回1，如果搜索的文件不存在，则返回2。我们利用这些返回值就可进行一些自动化的文本处理工作。

#### 格式

	grep [option] pattern file

#### 例子

1. 查找指定进程

		ps -ef | grep svn

2. 查找指定进程个数

		ps -ef|grep -c svn

3. 从文件中读取关键词进行搜索 (输出test.txt文件中含有从test2.txt文件中读取出的关键词的内容行)

		cat test.txt | grep -f test2.txt

4. 从文件中读取关键词进行搜索 且显示行号

		cat test.txt | grep -nf test2.txt

5. 从文件中查找关键词

		grep "xxx" test.txt

6. 从多个文件中查找关键词

		grep "xxx" test1.txt test2.txt

7. 找出以u开头的行内容

		cat test.txt | grep ^u	

8. 输出以hat结尾的行内容

		cat test.txt | grep hat$

9. 显示包含ed或者at字符的内容行

		cat test.txt | grep -E "ed|at"

## 19. wc

> Linux系统中的wc(Word Count)命令的功能为统计指定文件中的字节数、字数、行数，并将统计结果显示输出。

#### 格式

	wc [选项]文件…

#### 例子

1. 查看文件的字节数、字数、行数

		wc test.txt

		说明：
		
		7 8 70 test.txt 
		行数 单词数 字节数 文件名

## 19. ps

> Linux中的ps命令是Process Status的缩写。ps命令用来列出系统中当前运行的那些进程。ps命令列出的是当前那些进程的快照，就是执行ps命令的那个时刻的那些进程，如果想要动态的显示进程信息，就可以使用top命令。

#### 命令格式

	ps [参数]

#### 例子

1. 显示所有进程信息

		ps -A

2. 显示指定用户信息

		ps -u root

3. 显示所有进程信息，连同命令行

		ps -ef

4. ps 与grep 常用组合用法，查找特定进程

		ps -ef | grep ssh

5. 将目前属于您自己这次登入的 PID 与相关信息列示出来

		ps -l
		
		注：
		ps 仅会列出与目前所在的 bash shell 有关的 PID 而已，所以， 当使用 ps -l 的时候，只有两个 PID

6. 列出目前所有的正在内存当中的程序

		ps aux

7. 把所有进程显示出来，并输出到test.txt文件

		ps -aux > test.txt


## 20. kill

> Linux中的kill命令用来终止指定的进程（terminate a process）的运行，是Linux下进程管理的常用命令。通常，终止一个前台进程可以使用Ctrl+C键，但是，对于一个后台进程就须用kill命令来终止，我们就需要先使用ps/pidof/pstree/top等工具获取进程PID，然后使用kill命令来杀掉该进程。kill命令是通过向进程发送指定的信号来结束相应进程的。在默认情况下，采用编号为15的TERM信号。TERM信号将终止所有不能捕获该信号的进程。对于那些可以捕获该信号的进程就要用编号为9的kill信号，强行“杀掉”该进程。

#### 格式

	kill [参数] [进程号]

#### 命令参数

	-l 信号，若果不加信号的编号参数，则使用“-l”参数会列出全部的信号名称 
	-a 当处理当前进程时，不限制命令名和进程号的对应关系 
	-p 指定kill 命令只打印相关进程的进程号，而不发送任何信号 
	-s 指定发送信号 
	-u 指定用户

#### 例子

1. 列出所有信号名称

		kill -l

		只有第9种信号(SIGKILL)才可以无条件终止进程，其他信号进程都有权利忽略。 
		下面是常用的信号：
		HUP 1 终端断线 
		INT 2 中断（同 Ctrl + C） 
		QUIT 3 退出（同 Ctrl + \） 
		TERM 15 终止 
		KILL 9 强制终止 
		CONT 18 继续（与STOP相反， fg/bg命令） 
		STOP 19 暂停（同 Ctrl + Z）

2. 先用ps查找进程，然后用kill杀掉

		ps -ef | grep vim
		kill 进程号

3. 彻底杀死进程

		kill –9 进程号

		kill -9 pid等于kill -s 9 pid 

## 21. killall 

> Linux系统中的killall命令用于杀死指定名字的进程（kill processes by name）。我们可以使用kill命令杀死指定进程PID的进程，如果要找到我们需要杀死的进程，我们还需要在之前使用ps等命令再配合grep来查找进程，而killall把这两个过程合二为一，是一个很好用的命令。

## 格式

	killall[参数][进程名]

## 例子

1. 杀死所有同名进程

		killall vi

2. 向进程发送指定信号

		后台运行程序：vi & 
		杀死vi进程：killall -TERM vi 或者 killall -KILL vi

3. 把所有的登录后的shell给杀掉

		killall -9 bash

		运行命令：killall -9 bash 后，所有bash都会被卡掉了，所以当前所有连接丢失了。需要重新连接并登录。

## 22. free 

> free命令可以显示Linux系统中空闲的、已用的物理内存及swap内存,及被内核使用的buffer。在Linux系统监控的工具中，free命令是最经常使用的命令之一。

#### 格式

	free [参数]

#### 参数

	-b 　以Byte为单位显示内存使用情况。 
	-k 　以KB为单位显示内存使用情况。 
	-m 　以MB为单位显示内存使用情况。 
	-g 以GB为单位显示内存使用情况。 
	-o 　不显示缓冲区调节列。 
	-s <间隔秒数> 　持续观察内存使用状况。 
	-t 　显示内存总和列。 
	-V 　显示版本信息。

#### 例子

1. 显示内存使用情况

		free 
		free -g 
		free -m

2. 周期性的查询内存使用信息

		free -s 10

## 23. awk

> awk是一个强大的文本分析工具，相对于grep的查找，sed的编辑，awk在其对数据分析并生成报告时，显得尤为强大。简单来说awk就是把文件逐行的读入，以空格为默认分隔符将每行切片，切开的部分再进行各种分析处理。

#### 格式

	awk '{pattern + action}' {filenames}

#### 例子

1. 每行按空格或TAB分割，输出文本中的1、4项

		用法一： awk '{[pattern] action}' {filenames}   # 行匹配语句 awk '' 只能用单引号

		# log.txt
		2 this is a test
		3 Are you like awk
		This's a test
		10 There are orange,apple,mongo

		awk '{print $1,$4}' log.txt
		---------------------------
		2 a
 		3 like
 		This's
 		10 orange,apple,mongo

2. 只是显示最近登录的5个帐号

		last -n 5 | awk  '{print $1}'

		awk工作流程是这样的：
		读入有'\n'换行符分割的一条记录，然后将记录按指定的域分隔符划分域，填充域，$0则表示所有域,$1表示第一个域,$n表示第n个域。默认域分隔符是"空白键" 或 "[tab]键",所以$1表示登录用户，$3表示登录用户ip,以此类推。

3. 只是显示/etc/passwd的账户

		cat /etc/passwd |awk  -F ':'  '{print $1}'
		-F指定域分隔符为':'

4. 只是显示/etc/passwd的账户和账户对应的shell,而账户与shell之间以tab键分割

		cat /etc/passwd |awk  -F ':'  '{print $1"\t"$7}'

参考: [https://blog.csdn.net/young_kim1/article/list/3](https://blog.csdn.net/young_kim1/article/list/3)