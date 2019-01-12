## git cherry-pick合并commit
###

> git cherry-pick可以选择某一个分支中的一个或几个commit(s)来进行操作（操作的对象是commit）。例如，假设我们有个稳定版本的分支，叫v2.0，另外还有个开发版本的分支v3.0，我们不能直接把两个分支合并，这样会导致稳定版本混乱，但是又想增加一个v3.0中的功能到v2.0中，这里就可以使用cherry-pick了。

简单地说就是对已经存在的commit进行再次提交。

使用方法如下：

	git cherry-pick <commit id>

查询commit id 的查询可以使用git log查询（查询版本的历史）

比如有某个commit：

	commit 0771a0c107dbf4c96806d22bbc6ef4c58dfe7075
	Author: xxx <xxx>
	Date:   Mon Aug 8 14:41:54 2016 +0800
	[modify] [what] commit的备注信息
	
假设`0771a0c107dbf4c96806d22bbc6ef4c58dfe7075`就是我们想要的commit id

注意：当执行完 cherry-pick 以后，将会生成一个新的提交；这个新的提交的哈希值和原来的不同，但标识名一样；(commit id会变)

### 实践

首先切换到你要添加commit的分支，如：你要将A分支上面的commit添加到B分支上面，我们可以要先切换到B分支上面。（注意：cherry-pick是一个本地的操作，假如你pull代码之后有人在A分支上有了新的commit，需要你先pull代码再进行cherry-pick，原因及其错误提示请见最后）。

	git checkout B
	
将`0771a0c107dbf4c96806d22bbc6ef4c58dfe7075`这个commit（提交）合并到B分支上面。正常情况下，可以给出全部的commit id，也可以只给出前面的一段，只要你提交中没有这一段重复的就好，剩下的部分git会帮你填充。

	git cherry-pick 0771a0c107dbf4c #将上面的commit id为0771a0c107dbf4c96806d22bbc6ef4c58dfe7075的提交添加到B分支上面
	
1. 成功的情况

顺利的话，出现下面的情况证明你已经成功了　　
		
	Finished one cherry-pick.
	# On branch B
	# Your branch is ahead of 'origin/B' by 1 commits.
	
2. 有冲突的情况

下面是有文件冲突，和`15a2b6c61927e5aed6718de89ad9dafba939a90b`这个提交冲突

	Automatic cherry-pick failed.  After resolving the 	conflicts,
	mark the corrected paths with 'git add <paths>' or 	'git rm <paths>'
	and commit the result with:
 
   		git commit -c 15a2b6c61927e5aed6718de89ad9dafba939a90b
   		
解决的冲突的方法也和普通的一样，手工检查。打开冲突的文件，解决冲突。 执行add命令、执行commit命令，最后再提交即可。

### 总结

单个commit只需要`git cherry-pick <commit id>`

多个commit 只需要`git cherry-pick <commit id1>..<commit id100> `(两个commit id中间有*两个点*)

**注意，不包含第一个<commit id>， 即 `git cherry-pick (commit id1..commit id100]`**

ref: 

1. [https://www.cnblogs.com/0201zcr/p/5752771.html](https://www.cnblogs.com/0201zcr/p/5752771.html)
2. [https://blog.csdn.net/w958796636/article/details/78492017](https://blog.csdn.net/w958796636/article/details/78492017)