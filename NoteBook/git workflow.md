## git workflow
###

> 今天偶然发现自己之前对git的某些操作理解有误...虽然不影响使用, 但我觉得有必要记录一下

### 一. 先来简要写下我自己的git workflow

1. Fork某项目到自己帐号

       https://github.com/original-name/repo-name: 源仓库的地址
       https://github.com/your-username/repo-name: Fork到自己帐号后的地址

2. clone项目到本地

       git clone https://github.com/your-username/repo-name

3. 添加远程仓库(方便之后同步远程仓库)

       cd $working_dir/repo-name
       git remote add upstream https://github.com/original-name/repo-name
        
4. 同步远程仓库

       git checkout master
       git fetch upstream
       git rebase upstream/master
       git push origin master
    
       理解上主要的偏差在这里...后面详细说
       这里的第一小步和第二小步可以交换
       第四小步是为了同步自己帐号该仓库的master分支(好像没有实际作用...为了好看- -, 因为提交的new-branch分支是最新且同步的...还有待考证)
    
5. 新建分支开发

       git checkout -b new-branch
       coding...
       git add .
       git commit -m "..."
       git push origin new-branch
    
6. 提交PR

另外, 第4个步骤我以前也用过:

    git checkout master
    git pull upstream master
    git push origin master
    
其实差不多, 差别后面讲...


### 二. 我将主要的理解偏差归为了两类问题:

1. 对git中origin, upstream, master等关键词的理解
2. 对git push, git pull, git fetch的理解

#### origin & upstream

1) 当你从GitHub上clone一个repo到本地时, 除非你已是这个repo的maintainer, 否则你是不能向其直接push的, 此时, 该远程的repo对于本地repo来说, 就是upstream.

2) 当你从GitHub上fork一个repo之后, 再clone forked repo到本地， 你就可以任意向其push, 此时, 远程的repo就是origin.

#### git push & git pull 

> git push与git pull是一对推送/拉取分支的git命令

1) git push 使用本地的对应分支来更新对应的远程分支

        git push <远程主机名> <本地分支名>:<远程分支名>
        注意: 命令中的本地分支是指将要被推送到远端的分支，而远程分支是指推送的目标分支，即将本地分支合并到远程分支。 
        如果省略远程分支名，则表示将本地分支推送与之存在”追踪关系”的远程分支(通常两者同名)，如果该远程分支不存在，则会被新建。
        
        比如 git push origin master
        上面命令表示，将本地的master分支推送到origin主机的master分支。如果后者不存在，则会被新建。 
        origin是一个远程厂库地址。
        
        如果省略本地分支名，则表示删除指定的远程分支，因为这等同于推送一个空的本地分支到远程分支，这条命令是删除远程master分支。
        git push origin :master
        # 等同于
        git push origin --delete master
        上面命令表示删除origin主机的master分支。
        
        如果当前分支与远程分支之间存在追踪关系（即分支名相同），则本地分支和远程分支都可以省略。
        git push origin
        上面命令表示，将当前分支推送到origin主机的对应分支。
        
        如果当前分支只有一个追踪分支，那么主机名都可以省略。
        git push
        
        如果当前分支与多个主机存在追踪关系，则可以使用-u选项指定一个默认主机，这样后面就可以不加任何参数使用git push。
        git push -u origin master
        上面命令将本地的master分支推送到origin主机，同时指定origin为默认主机，后面就可以不加任何参数使用git push了。
        
        不带任何参数的git push，默认只推送当前分支，这叫做simple方式。此外，还有一种matching方式，会推送所有有对应的远程分支的本地分支。Git 2.0版本之前，默认采用matching方法，现在改为默认采用simple方式。如果要修改这个设置，可以采用git config命令。
        git config --global push.default matching
        # 或者
        git config --global push.default simple
        
        还有一种情况，就是不管是否存在对应的远程分支，将本地的所有分支都推送到远程主机，这时需要使用–all选项。
        git push --all origin
        上面命令表示，将所有本地分支都推送到origin主机。

2) git pull 获取并合并其他的厂库，或者本地的其他分支。

        git pull 与 git push操作的目的相同，但是操作的目标相反。命令格式如下：
        git pull <远程主机> <远程分支>:<本地分支>
        
        比如 git pull origin master:my_test
        上面的命令是将origin厂库的master分支拉取并合并到本地的my_test分支上。
        如果省略本地分支，则将自动合并到当前所在分支上。如下：git pull origin master
        
3) 如果你想参与github上的一些优秀的项目，则下面提供一个通用的例子： 

        首先，需要一个github的账号，并fork一个你感兴趣的repository。 
        下面描述过程中会涉及两个远程主分支，为了很好的区别，我们把fork出来的主分支称为远程A repository，fork from的分支称为远程B repository
        
        git clone <远程Arepository> #克隆你fork出来的分支
        git remote add <远程Brepository标签> git@github.com:XXXX/xxx.git #添加远程Brepository标签
        git pull <远程B厂库标签> master:master  #从远程Brepository的master分支拉取最新objects合并到本地master分支
        git checkout -b my_test #切换到要修改的分支上
        coding... #在工作区coding
        git add .#将修改保存到索引区
        git commit -a #将修改提交到本地分区
        git push origin my_test:my_test #将本地分支my_test提交到远程A repository的my_test分支上
        submit PR
        
我之前理解有偏差的地方:
1. 不太清楚origin/master和upstream/master的区别...其实这俩是不同的分支, 其中origin, upstream代表不同的主机名
2. 不知道原来git push origin master是省略了远程分支名master
3. 不知道原来git pull upstream master是合并到当前分支(而不是master分支), 之前一直是在本地master下进行这步, 所以没问题...


#### git fetch & git pull

1) git fetch 相当于是从远程获取最新到本地，不会自动merge，如下指令：

        git fetch orgin master // 将远程仓库的master分支下载到本地origin/master中
        git merge origin/master // 进行合并
        
        也可以用以下指令：
        git fetch origin master:tmp // 从远程仓库master分支获取最新，在本地建立tmp分支(和origin/master一致)
        git diff tmp // 將當前分支和tmp進行對比
        git merge tmp // 合并tmp分支到当前分支
        
git fetch 命令总结:

    git fetch <远程主机名>   // 这个命令将某个远程主机的更新全部取回本地
    
    如果只想取回特定分支的更新，可以指定分支名：
    git fetch <远程主机名> <分支名> // 注意之间有空格
    
    最常见的命令如取回origin 主机的master分支：
    git fetch origin master

2) git pull 相当于是从远程获取最新版本并merge到本地

        git pull origin master
        git pull 相当于从远程获取最新版本并merge到本地
        
        在实际使用中，git fetch更安全一些
        
git pull 命令总结:

    git pull <远程主机名> <远程分支名>:<本地分支名>   // 即将远程主机的某个分支的更新取回，并与本地指定的分支合并
    
所以简单来说 git pull 相当于 git fetch + git merge

ref:

1. [github中origin和upstream的区别](https://blog.csdn.net/liuchaoxuan/article/details/80656145)
2. [git push & git pull 推送/拉取分支](https://blog.csdn.net/litianze99/article/details/52452521)
3. [Git fetch & pull 详解](https://blog.csdn.net/qq_36113598/article/details/78906882)
4. [git fetch 和git pull 的差别](https://www.cnblogs.com/qiu-Ann/p/7902855.html)
