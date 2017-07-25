## Docker Beego
###

[Docker](https://www.docker.com/)是一个快速创建一致的开发和部署环境的工具,下面来我就记录一下这两天研究Docker的经历。

由于实习要求，我的目标是将写完的项目放到Docker容器里跑通，从而做到不用放到服务器上再去配置那么麻烦。

#### 一.安装Docker
   作为一位windows用户，只想说真的坑爹！！！配置了一天勉强跑通后然而运行命令时各种出错我就不吐槽了。最后还好明智地转向Linux，ubuntu下运行下面两条命令即可：

	$ sudo apt-get update
	$ sudo apt-get install docker.io

#### 二.安装 Golang Container
 
  你只要运行下面的命令就可以从Golang官方库创建一个包括Golang开发环境的Docker Container：

	$ sudo docker run -it golang /bin/bash

  这时, 你已经有了最新的 Golang 开发环境，利用下面的命令来查看golang版本：

	$ sudo go version

  你第一次运行 ```docker run <image name>``` 的时候, 如果 Docker 没有在本机找到对应的 Image, 则会自动到 Docker 库中寻找

  通过下面的命令, 你可以查看本地存在的 Docker Image.

	$ sudo docker images

  通过下面的命令, 你可以查看你创建的 Container.

	$ sudo docker ps -a

#### 三.运行容器

	$ sudo docker run -it -v 
	/home/tangl/programming/go/hello-world/:/go/src/hello-world golang /bin/bash

我们使用了选项 ```-v /home/leicao/programming/go/hello-world/:/go/src/hello-world```,

它将我的 Ubuntu 主机上的目录``` /home/tangl/programming/go/hello-world/``` 挂载到创建的 Docker Container 的``` /go/src/hello-world ```目录.

这样, 在我的 Docker Container 里面, 我便可以得到我的 hello world 源码了. 之后我 ```cd src/hello-world/``` 并编译它``` go build hello.go``` 最后``` ./hello ```来运行它.

#### 四.创建Beego镜像

1.首先创建一个 Dockerfile:

	# Base image is in https://registry.hub.docker.com/_/golang/
	# Refer to https://blog.golang.org/docker for usage
	FROM golang
	MAINTAINER tangl

	# ENV GOPATH /go

	# Install beego & bee
	RUN go get github.com/astaxie/beego
	RUN go get github.com/beego/bee

```FROM golang``` 这个 Docker image 从官方的 Golang Image 创建, 之后我们运行 ```RUN go get github.com/astaxie/beego ```和 ```RUN go get github.com/beego/bee ```来安装 Beego 和 Bee 的依赖.

2.然后我们可以到这个Dockerfile所在目录下运行下面的命令：
	
	$ sudo docker build -t leicao/beego .（别忘了最后的点！！！）

3.然后可以使用 bee 工具来创建 beego 应用:

	$ sudo docker run --rm -v "$(pwd)":/go/src/ 
	-w /go/src tangl/beego bee new beego-docker

```--rm ```告诉 Docker 自动删除这个 Container 当执行结束后.

``` -v "$(pwd)":/go/src/``` 会挂载我的当前目录到 Docker Container 里面的``` /go/src``` 目录.

``` -w /go/src``` 指定运行命令的目录. ```tangl/beego``` 是这里所使用的 Docker image, 也就是我们刚刚创建的那个 Beego Image.

最后通过 ```bee new beego-docker ```创建了一个 beego 应用 beego-docker.

4.最后就可以运行项目了

	$ sudo docker run --rm -v "$(pwd)"/beego-docker:/go/src/beego-docker 
	-w /go/src/beego-docker -p 8081:8080 leicao/beego bee run

这里使用了一个新的选项 ```-p 8081:8080```, 它将 Docker container 内部的 8080 端口映射到主机的 8081 端口.

这时, 我们的 beego 应用已经可以访问了: [http://localhost:8081](http://localhost:8081)