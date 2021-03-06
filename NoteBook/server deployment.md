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


#### 五. Ubuntu搭建WordPress环境

1. 安装PHP

		$ apt-get update
		//安装PHP
		$ apt-get -y install php

		$ apt-get -y install php-mysql php-fpm

2. 安装完毕之后配置php-fpm 

		$ vim /etc/php/7.0/fpm/php.ini

		//;cgi.fix_pathinfo=1 改为

		cgi.fix_pathinfo=0

3. 重启php-fpm服务

		$ service php7.0-fpm restart

4. 安装Mysql

		$ apt-get -y install mysql-server-5.7

5. 设置完密码，WordPress环境就搭建完毕


#### 六. Ubuntu部署WordPress

1. 用git拉取WordPress源码

		$ git clone https://github.com/JellyBool/wordpress.git /var/www/wordpress

2. 配置Mysql

		$ mysql -u root -p

		在mysql中执行：

		CREATE DATABASE wordpress DEFAULT CHARACTER SET utf8 COLLATE utf8_unicode_ci;

		CREATE USER '用户名' IDENTIFIED BY '密码';

		GRANT ALL PRIVILEGES ON wordpress.* TO '用户名';

		quit

		注：上面的用户名和密码要根据自己的需求设置

3. 配置 Nginx

		$ vim /etc/nginx/sites-available/default

		打开配置文件，配置：

		root /var/www/wordpress;


		index index.php index.html index.htm index.nginx-debian.html;

		# 注意我们添加了 index.php


		location / {

        try_files $uri $uri/ /index.php?$query_string;

		}

		location ~ \.php$ {

        try_files $uri /index.php =404;

        fastcgi_split_path_info ^(.+\.php)(/.+)$;

        fastcgi_pass unix:/var/run/php/php7-fpm.sock;

        fastcgi_index index.php;

        fastcgi_param SCRIPT_FILENAME $document_root$fastcgi_script_name;

        include fastcgi_params;

		}

4. 配置完成后重启下Nginx服务

		$ service nginx restart

5. 完成到这一步，我们输入域名可以访问到Nginx的安装教程页面

		根据要求填完信息后提交，然后会显示一个页面提示：

		抱歉，我不能写入wp-config.php文件，您可以手工创建wp-config.php文件并将以下信息贴入其中。

		然后我们来手工创建wp-config.php

		$ cd /var/www/wordpress

		//赋予权限
		$ chown -R www-data:www-data /var/www/wordpress

		$ vim wp-config.php

		然后将网页中提示的代码复制进去

		点击继续安装并按相关要求填写后就可以成功安装WordPress啦

6. 配置WordPress文件上传

		再次打开wp-config.php文件，将下面三行代码复制进去：

		define('FS_METHOD', 'direct');

		define('FS_CHMOD_DIR', 0777);

		define('FS_CHMOD_FILE', 0777);

		//安装其他的 php 扩展

		apt install -y php7.0-gd php7.0-mbstring php7.0-xmlrpc

7. 访问你的域名，就可以看到WordPress的默认页面了



参考：

1. [从零部署一个网站](https://www.codecasts.com/series/deploy-a-website-from-scratch)
2. [Ubuntu LNMP 部署 WordPress：环境准备](https://www.codecasts.com/blog/post/lnmp-wordpress-deploy-environment-setup)
3. [Ubuntu LNMP 部署 WordPress](https://www.codecasts.com/blog/post/deploy-wordpress-on-lnmp)