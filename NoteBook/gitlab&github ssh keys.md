## gitlab/github 多账户设置ssh keys
###

> 本文介绍如何同时使用gitlab和github

#### 首先都已经注册了gitlab和github的账户

#### 生成秘钥

	ssh-keygen -t rsa -C "注册的gitlab邮箱"
	
提示要输入名称, 不管, 一路回车, 也不要设置密码 

随后查看`.ssh`目录，可以看到公私秘钥已经生成，名称分别为`id_rsa.pub`、`id_rsa`

	ssh-keygen -t rsa -C "注册的github邮箱"

这次名称输入比如`id_rsa_github`

可以看到生成的公私秘钥已经分别被命名为`id_rsa_github.pub`和`id_rsa_github `

#### 添加ssh key

则现在在`~/.ssh`路径下分别有四个文件
	
	id_rsa
	id_rsa.pub
	id_rsa_github
	id_rsa_github.pub
	
把`id_rsa.pub`和`id_rsa_github.pub`分别复制到gitlab和github的SSH Keys中

#### 添加config

gitlab和github的秘钥是分开生成了，可怎么让这两份秘钥分别对应到相应的远程仓库呢？就是让`id_rsa.pub`认得gitlab,让`id_rsa_github.pub`认得github。既然不能自动识别，那就只好手动设置了：

在`.ssh`目录下新建config文件

config内容
	
	# gitlab
	Host gitlab
   		HostName gitlab.com       
   		IdentityFile ~/.ssh/id_rsa
   		
	# github
	Host github
		HostName github.com
		IdentityFile ~/.ssh/id_rsa_github
		
其中Host对应的名称是一个别名，命名可以随意，用来进行远程连接，当然使用真实的主机名称也是可以的。HostName和IdentityFile就是各自主机名称以及对应的秘钥文件了~
这样配置之后，两份秘钥也就对应到各自相应的仓库上了。通过设置别名，也就可以设置任意多的账户了~

#### 设置仓库用户信息

Git 配置信息也有三个地方可以存储，根据加载顺序依次为：

1. `/etc/gitconfig` 文件: 包含系统上每一个用户及他们仓库的通用配置。 如果使用带有 --system 选项的 `git config` 时，它会从此文件读写配置变量。
2. `~/.gitconfig` 或 `~/.config/git/config` 文件只针对当前用户。 可以传递 --global 选项让 Git 读写此文件。
3. 当前使用仓库的 Git 目录中的 config 文件（就是 .git/config）

不同仓库链接不同的服务器，所用的git用户信息也不同。可以把常用的git用户信息配置到 `~/.gitconfig` 中，不常用的我们在仓库中单独配置。以常用 github 为例：

	git config --global user.name "githubuser"
	git config --global user.email "githubuser@xyz.com"
	
进入本地 gitlab 仓库配置 git 用户信息

	~/gitlab$ git config --local user.name "gitlabuser"
	~/gitlab$ git config --local user.email "gitlabuser@xyz.com"
	
	
ref:

1. [https://www.cnblogs.com/qlshine/p/6041301.html](https://www.cnblogs.com/qlshine/p/6041301.html)
2. [https://www.cnblogs.com/520yang/articles/4654601.html](https://www.cnblogs.com/520yang/articles/4654601.html)
3. [https://www.cnblogs.com/kelsen/archive/2018/01/24/8342239.html](https://www.cnblogs.com/kelsen/archive/2018/01/24/8342239.html)