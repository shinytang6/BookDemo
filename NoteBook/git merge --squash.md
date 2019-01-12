## git merge --squash
###

我们经常会面临着将dev分支或者很多零散的分支merge到一个公共release分支里。但是有一种情况是需要我们处理的，就是在dev分支里有很多commit记录，而这些commit是无需在release里体现的。

`develop`主分支

![https://images2015.cnblogs.com/blog/202205/201611/202205-20161103115615096-1372379989.png](https://images2015.cnblogs.com/blog/202205/201611/202205-20161103115615096-1372379989.png)

develop``主分支最近的一个commit是”fix imageprint bug”。

我们拉出一个分支进行项目开发，里面会有很多commit记录。

	git checkout -b develop_newfeature_ImportDataInterface

`develop_newfeature_ImportDataInterface`分支的commit log是和`develop`一模一样的。我们在该分支上添加点commit。

![https://images2015.cnblogs.com/blog/202205/201611/202205-20161103115615908-1587207513.png](https://images2015.cnblogs.com/blog/202205/201611/202205-20161103115615908-1587207513.png)

现在我们想将`develop_newfeature_ImportDataInterface`分支的commit merge到`develop`主分支里去。在合并进`develop`的时候我们希望在`develop`的commit log里只看见一次commit，而且这个commit的message不是很随意的，而是符合正规提交流程的约定格式的，比如，”develop:finished import data interface”。
我们就需要借助`git merge --squash`命令来重新提交。（这是一个明确的merge操作不同于`git rebase`，不要搞混淆这两个命令的作用。）

	git checkout develop
	git merge --squash develop_newfeature_ImportDataInterface
	
	Updating cc1fea6..e6fb522 
	Fast-forward  
	Squash commit -- not updating HEAD  
	1.txt | 3 +++  
	1 file changed, 3 insertions(+) 
	
`--squash`会暂停commit提交。要不然一个merge会自动提交commit。

我们查看git状态会看到：

![https://images2015.cnblogs.com/blog/202205/201611/202205-20161103115616440-1720497926.png](https://images2015.cnblogs.com/blog/202205/201611/202205-20161103115616440-1720497926.png)

`1.txt`文件是我们修改的文件，它现在等待被commit。现在我们只需要重新提交即可。

	git commit -m'develop:finished import data interface' 
	
![https://images2015.cnblogs.com/blog/202205/201611/202205-20161103115617033-39200975.png](https://images2015.cnblogs.com/blog/202205/201611/202205-20161103115617033-39200975.png)

这样每次merge时的日志信息就会一目了然，就算回头reset也方便。

ref: [https://www.cnblogs.com/wangiqngpei557/p/6026007.html](https://www.cnblogs.com/wangiqngpei557/p/6026007.html)