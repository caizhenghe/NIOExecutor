使用单线程实现同步非阻塞的状态机模型：

程序启动时自动开启执行器，每隔一秒遍历执行任务列表中的Task

输入任意字符提交Task给任务列表

执行完毕后将Task置为STOP状态并移出列表

每个Task都是非阻塞的

-----------------------------------------------------------------


拉取远程仓库
git clone url

从远程分支更新代码
git pull

提交本地代码到远程分支
git add .
git commit --amend
git push origin -u HEAD:master

合并分支
git rebase