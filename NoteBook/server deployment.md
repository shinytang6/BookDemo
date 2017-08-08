## 服务器部署
###

#### 一. 准备工作

1. 购买域名

2. 购买一个云服务器

#### 二. 登录云服务器ECS并安装Nginx

1. 登录服务器

		$ ssh root@外网IP

2. 更新软件包

		$ apt-get update

3. 安装Nginx

		$ apt-get install nginx

然后在网页中输入外网IP应该就可以访问到Nginx默认的页面了。

#### 三. 域名解析

可以到对应的域名提供商网站将域名解析到对应的外网IP

#### 四. 部署自己的代码到服务器

1. 进入nginx默认配置文件

		$ cd /etc/nginx/sites-available
		$ vim default

2. 修改root路径配置

		将root /var/www/html修改为root /var/www/test

3. 从github克隆代码到服务器(这里Github起到了中间人的作用)

		$ cd /var/www
		$ git clone xxxxxx test

4. 重启nginx

		$ service nginx restart

5. 输入域名即可访问自己的代码


