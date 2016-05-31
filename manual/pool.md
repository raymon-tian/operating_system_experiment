<head>
<title>并行搜索</title>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
</head>

# 并行搜索
## API参考
- 多线程环境下，使用readdir_r而不是readdir
- [readdir_r](api/readdir.html)
- [opendir_r](api/opendir.html)
- [closedir_r](api/closedir.html)

## 例子
- [统计目录下文件个数, 不包括子目录](pool/readdir.c)
- [线程池技术](pool/thread.c)

## 线程池技术 
- [Wikipedia参考](http://en.wikipedia.org/wiki/Thread_pool_pattern)
- <img src="pool.png"/>
- Thread pool pattern is where a **fixed number** of threads are created to perform a number of tasks, which are usually organized in a queue.
- The results from the tasks being executed might also be placed in a queue, or the tasks might return no result. 
- Typically, **there are many more tasks than threads**.
- As soon as a thread completes its task, it will request the next task from the queue until all tasks have been completed. 

## 线程池优点 
- If the number of tasks is very large, then **creating a thread for each one may be impractical**.
- Creating and destroying a thread and its associated resources is an expensive process in terms of time. 
- An excessive number of threads will also waste memory, and context-switching between the runnable threads also damages performance. 
- Another advantage of using a thread pool over creating a new thread for each task is thread creation and destruction overhead is negated(抵消), which may result in better performance and better system stability.

## 题目
- sscan.c: 扫描/usr/include目录下所有.h文件，统计包含单词define的行数总和
    + 包括/usr/include目录下的子目录
    + 统计结果应该与以下命令的结果相同<br>
      grep -R define /usr/include | wc -l
    + 使用串行的算法即可

- pscan.c: 与Serial的功能相同
    + 使用基于线程池的并行算法
    + 使用固定数目的线程进行处理 
        - 通常，该数目等于CPU核心个数
        - 通常，该数目远远小于需要处理的文件个数
