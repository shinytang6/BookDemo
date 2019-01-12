## git rebase -i
###

> 开发的时经常会面临一个常见的问题，即多个commit 需要合并为一个完整的commit提交。

具体操作如下：

`develop_fixbug_imageprint` 分支是我基于远程`develop`分支拉出来的开发分支，我会基于这个分支来fix一些bug。我们先分别看下`develop`、`develop_fixbug_imageprint` 的commit log。

	git checkout develop
	git log

![https://images2015.cnblogs.com/blog/202205/201610/202205-20161023113507420-786891997.png](https://images2015.cnblogs.com/blog/202205/201610/202205-20161023113507420-786891997.png)

	git checkout develop_fixbug_imageprint
	git log
	
![https://images2015.cnblogs.com/blog/202205/201610/202205-20161023113508467-1921220392.png](https://images2015.cnblogs.com/blog/202205/201610/202205-20161023113508467-1921220392.png)


发现`develop_fixbug_imageprint`的commit log和`devleop` commit log 一模一样。我们现在切换到`develop_fixbug_imageprint`进行一些操作。

先添加一个1.txt文件，执行

	git add .
	git commit –m’add 1.txt’
再添加一个2.txt文件，执行

	git add .
	git commit –m’add 2.txt’
	
![https://images2015.cnblogs.com/blog/202205/201610/202205-20161023113509373-318997412.png](https://images2015.cnblogs.com/blog/202205/201610/202205-20161023113509373-318997412.png)

现在`develop_fixbug_imageprint`分支里有两个commit。这两个commit都是为了fix当前这个bug而做的两个提交。现在我们要合并代码上主`develop`分支。总不能把这两个commit直接提交上去，这里还好只有两个commit，但是一般项目开发周期两个星期的话，你起码有十几个commit。那这样提交上去之后就很难管理和跟踪。（我以前都是这样干的，现在发现这样不好跟踪管理。）

那么我们如何完成这个合并commit呢，就需要用到`git rebase`命令。

先来解释下`git rebase`:
> 你其实可以把它理解成是“重新设置基线”，将你的当前分支重新设置开始点。这个时候才能知道你当前分支与你需要比较的分支之间的差异。

比如，`develop_fixbug_imageprint`分支是来自`develop`分支，那么从test commit开始后面我们基本上都是各自发展，现在在`develop_fixbug_imageprint`分支上有两个commit，我们需要找一个基准，这个基准就是git需要找到哪些是你后来提交的commmit，总得有个参照。

	git rebase –i develop

![https://images2015.cnblogs.com/blog/202205/201610/202205-20161023113510404-2097328646.png](https://images2015.cnblogs.com/blog/202205/201610/202205-20161023113510404-2097328646.png)

git rebase立马知道`develop`与`develop_fixbug_imageprint`之间的差异。因为我们是基于`develop`设置rebase的。`git rebase –i` ，这里的”-i“是指交互模式。就是说你可以干预rebase这个事务的过程，包括设置commit message，暂停commit等等。

当然 `git rebase –i + 分支名/commit id` 的分支名/commit id 是任意的，会根据具体的值比较当前commit与指定的commit之间的差异。

这里我们要求很简单就是合并之前的commit且重新设置commit message。
我们设置第二个”pick 657a291 add 2.txt” 为” s 657a291 add 2.txt”这里的s就是squash命令的简写。

![https://images2015.cnblogs.com/blog/202205/201610/202205-20161023113514467-1986177093.png](https://images2015.cnblogs.com/blog/202205/201610/202205-20161023113514467-1986177093.png)

跳出来了一个临时文件，最上面是两行commit message。我们修改下这个总体的commit message。

![https://images2015.cnblogs.com/blog/202205/201610/202205-20161023113515873-2022427931.png](https://images2015.cnblogs.com/blog/202205/201610/202205-20161023113515873-2022427931.png)

删除之前的两条message(ESC dd)，设置一总的message 然后保存退出。(ESC :wq)

![https://images2015.cnblogs.com/blog/202205/201610/202205-20161023113516857-7448338.png](https://images2015.cnblogs.com/blog/202205/201610/202205-20161023113516857-7448338.png)

我们再查看下log。

![https://images2015.cnblogs.com/blog/202205/201610/202205-20161023113517248-1249838164.png](https://images2015.cnblogs.com/blog/202205/201610/202205-20161023113517248-1249838164.png)

发现原来的两个commit squash成了一个。

其实在进入`git rebase –i` 交互模式后，你可以做的事情就很多了，可以设置edit 编辑commit 内容，可以让他暂停commit操作等等。

如果提交已经上传到远程，在`git push`时需要加上-f命令。

ref: [https://www.cnblogs.com/wangiqngpei557/p/5989292.html](https://www.cnblogs.com/wangiqngpei557/p/5989292.html)