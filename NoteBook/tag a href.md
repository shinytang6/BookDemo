## a标签中的href路径问题
###

在a标签中的href中，如果你写了一个路径，比如:`www.baidu.com`,其默认是以相对路径打开的，加上"http://"消息头就可以打开绝对路径。

举个刚刚碰到的例子：

下面是我原先写的download函数，目的是点击然后打开对应的官网，url从数据库中取出传给download函数，

假设现在数据库中的一个url值为`www.baidu.com`,那么这个函数将打开`http://localhost:xxxx/xx/www.baidu.com`这种相对路径页面，显然会报错

	download(url){
                window.open(url);
             }

所以应将download函数更改为：

	download(url){
               if (url.indexOf("http") !== 0) {
                window.open("http://" + url);
               } else {
                window.open(url);
               }
            }