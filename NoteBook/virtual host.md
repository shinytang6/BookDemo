## Apache配置虚拟主机
###

#### 一. 基于IP
 
1. 假设服务器有个IP地址为192.168.1.10，使用ifconfig在同一个网络接口eth0上绑定3个IP:


		[root@localhost root]# ifconfig eth0:1 192.168.1.11
		[root@localhost root]# ifconfig eth0:2 192.168.1.12
		[root@localhost root]# ifconfig eth0:3 192.168.1.13

2. 修改hosts文件，添加三个域名与之一一对应：

		192.168.1.11   www.test1.com
		192.168.1.12   www.test2.com
		192.168.1.13   www.test3.com

3. 建立虚拟主机存放网页的根目录，如在/www目录下建立test1、test2、test3文件夹，其中分别存放1.html、2.html、3.html

		/www/test1/1.html
		/www/test2/2.html
		/www/test3/3.html

4. 在httpd.conf中将附加配置文件httpd-vhosts.conf包含进来，接着在httpd-vhosts.conf中写入如下配置：
   
		<VirtualHost 192.168.1.11:80>
		　　ServerName www.test1.com
		　　DocumentRoot /www/test1/
		　　<Directory "/www/test1">
		 　　　　Options Indexes FollowSymLinks
		　　　　 AllowOverride None
		　　　　 Order allow,deny
		　　 　　Allow From All
		 　 </Directory>
		</VirtualHost>
		
		<VirtualHost 192.168.1.12:80>
		　　ServerName www.test1.com
		　　DocumentRoot /www/test2/
		　　<Directory "/www/test2">
		 　　　　Options Indexes FollowSymLinks
		　　　　 AllowOverride None
		　　　　 Order allow,deny
		　　 　　Allow From All
		 　 </Directory>
		</VirtualHost>
		
		<VirtualHost 192.168.1.13:80>
		　　ServerName www.test1.com
		　　DocumentRoot /www/test3/
		　　<Directory "/www/test3">
		 　　　　Options Indexes FollowSymLinks
		　　　　 AllowOverride None
		　　　　 Order allow,deny
		　　 　　Allow From All
		 　 </Directory>
		</VirtualHost>

5. 分别访问www.test1.com、www.test2.com、www.test3.com

#### 二. 基于主机名（最常用的）

1. 设置域名映射同一个IP，修改hosts：
		
		192.168.1.10  www.test1.com
		192.168.1.10  www.test2.com
		192.168.1.10  www.test3.com

2. 跟上面一样，建立虚拟主机存放网页的根目录

		/www/test1/1.html
		/www/test2/2.html
		/www/test3/3.html

3. 在httpd.conf中将附加配置文件httpd-vhosts.conf包含进来，接着在httpd-vhosts.conf中写入如下配置：

        如果在现有的web服务器上增加虚拟主机，必须也为现存的主机建造一个<VirtualHost>定义块。

		其中ServerName和DocumentRoot所包含的内容应该与全局的保持一致，且要放在配置文件的最前面，扮演默认主机的角色。

		(注意：最前面的那条是默认的！！！，也就是说出错了是访问第一条)

		NameVirtualHost *:80
		<VirtualHost *:80>  
		　　ServerName *
		
		　　DocumentRoot /www/ 
		
		</VirtualHost>
		
		<VirtualHost *:80>
		
		　　ServerName www.test1.com
		
		　　DocumentRoot /www/test1/
		
		　　<Directory "/www/test1">
		
		　　　　Options Indexes FollowSymLinks
		
		　　　　AllowOverride None
		
		　　　　Order allow,deny
		
		　　　　Allow from all
		
		　　</Directory>
		
		</VirtualHost> 
		
		 
		
		<VirtualHost *:80>
		
		　　ServerName www.test2.com
		
		　　DocumentRoot /www/test2/
		
		　　<Directory "/www/test2">
		
		　　　　Options Indexes FollowSymLinks
		
		　　　　AllowOverride None
		
		　　　　Order allow,deny
		
		　　　　Allow from all
		
		　　</Directory>
		
		</VirtualHost>
		<VirtualHost *:80>
		
		　　ServerName www.test3.com
		
		　　DocumentRoot /www/test3/
		
		　　<Directory "/www/test3">
		
		　　　　Options Indexes FollowSymLinks
		
		　　　　AllowOverride None
		
		　　　　Order allow,deny
		
		　　　　Allow from all
		
		　　</Directory>
		
		</VirtualHost>

4. 分别访问www.test1.com、www.test2.com、www.test3.com


#### 三. 基于端口

1.  修改配置文件
		　　	

		将原来的
		Listen 80
		改为
		Listen 80
		Listen 8080

2. 更改虚拟主机设置：

		<VirtualHost 192.168.1.10:80>
		    DocumentRoot /var/www/test1/
		    ServerName www.test1.com
		</VirtualHost>
		
		<VirtualHost 192.168.1.10:8080>
		    DocumentRoot /var/www/test2
		    ServerName www.test2.com
		</VirtualHost>


#### 注：

    hosts文件在目录 C:\Windows\System32\drivers\etc下！！！

	在httpd-vhosts.conf文件中，

	DocumentRoot表示网站根目录，ServerName表示需要服务的域名，80表示Apache监听80端口（一般为默认端口）

	在你正确写入以上代码之后，apache会就用户访问的域名对应配置中的ServerName选择合适的web目录输出html代码，

	若用户访问所指定的域名不符合所有条目时采用！！！默认项！！！，即默认访问httpd-vhosts.conf中第一条中的项目

参考：

1. [Apache 配置虚拟主机三种方式](http://www.cnblogs.com/hi-bazinga/archive/2012/04/23/2466605.html)

2. [Apache中同一IP使用多域名对应多个网站的方法](http://blog.csdn.net/zhanglei5415/article/details/6821066)