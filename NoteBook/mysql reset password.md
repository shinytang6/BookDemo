## ubuntu下忘记mysql密码的解决方法
###

> 印象中已经忘记过很多次mysql的密码了...随手记录一下

1. 停止mysql

        sudo /etc/init.d/mysql stop

2. 安全模式登录

        sudo mkdir -p /var/run/mysqld
        sudo chown mysql:mysql /var/run/mysqld
        sudo /usr/bin/mysqld_safe --skip-grant-tables --skip-networking &
        mysql -u root
        
3. 修改root密码

        use mysql;
        update user set authentication_string=PASSWORD("Your New Password") where User='root';
        update user set plugin="mysql_native_password";
        flush privileges;
        quit;
        
        
4. 不报错则修改成功, 登录mysql

        mysql -u root -p
        
        
ref:

1. [记录下ubuntu忘记mysql密码处理方法](https://blog.csdn.net/qq_43125439/article/details/83720758)