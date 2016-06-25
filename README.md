# operating_system_experiment
操作系统实验作业——linux系统调用学习，重定向、管道、多进程、多线程编程技术实现

//多进程
pid_t
fork
execvp
execlp
//多线程
pthread_t
pthread_create
pthread_join
pthread_mutex_t
pthread_mutex_init
pthread_mutex_destory
pthread_mutex_lock
pthread_mutex_unlock
pthread_cond_t
pthread_cond_init
pthread_cond_wait
pthread_cond_signal
pthread_cond_broadcast
//重定向
dup
dup2
//管道
pipe


实验作业



<html><head><meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
</head><body><h1>多进程题目</h1>
<h2>sh1.c: 实现shell程序，要求具备如下功能</h2>
<ul>
<li>支持命令参数
<pre>$ echo arg1 arg2 arg3
$ ls /bin /usr/bin /home
</pre>
</li><li>实现内置命令cd、pwd、exit
<pre>$ cd /bin
$ pwd
/bin
</pre>
</li></ul>

<h2>sh2.c: 实现shell程序，要求在第1版的基础上，添加如下功能</h2>
<ul>
<li>实现文件重定向
<pre>$ echo hello &gt;log
$ cat log
hello
</pre>
</li></ul>

<h2>sh3.c: 实现shell程序，要求在第2版的基础上，添加如下功能</h2>
<ul>
<li>实现管道
<pre>$ cat /etc/passwd | wc -l
</pre>
</li><li>实现管道和文件重定向
<pre>$ cat input.txt
3
2
1
3
2
1
$ cat &lt;input.txt | sort | uniq | cat &gt;output.txt
$ cat output.txt
1
2
3
</pre>
</li></ul>

<h1>多线程题目</h1>
<h2>pi1.c: 使用2个线程根据莱布尼兹级数计算PI</h2>
<ul>
<li>莱布尼兹级数公式:  1 - 1/3 + 1/5 - 1/7 + 1/9 - ... = PI/4</li>
<li>主线程创建1个辅助线程</li>
<li>主线程计算级数的前半部分</li>
<li>辅助线程计算级数的后半部分</li>
<li>主线程等待辅助线程运行結束后,将前半部分和后半部分相加</li>
</ul>

<h2>pi2.c: 使用N个线程根据莱布尼兹级数计算PI</h2>
<ul>
<li>与上一题类似，但本题更加通用化，能适应N个核心，需要使用线程参数来实现</li>
<li>主线程创建N个辅助线程</li>
<li>每个辅助线程计算一部分任务，并将结果返回</li>
<li>主线程等待N个辅助线程运行结束，将所有辅助线程的结果累加</li>
</ul>

<h2>sort.c: 多线程排序</h2>
<ul>
<li>主线程创建一个辅助线程</li>
<li>主线程使用选择排序算法对数组的前半部分排序</li>
<li>辅助线程使用选择排序算法对数组的后半部分排序</li>
<li>主线程等待辅助线程运行結束后,使用归并排序算法归并数组的前半部分和后半部分</li>
</ul>

<h2>pc1.c: 使用条件变量解决生产者、计算者、消费者问题</h2>
<ul>
<li>系统中有3个线程：生产者、计算者、消费者</li>
<li>系统中有2个容量为4的缓冲区：buffer1、buffer2</li>
<li>生产者生产'a'、'b'、'c'、‘d'、'e'、'f'、'g'、'h'八个字符，放入到buffer1</li>
<li>计算者从buffer1取出字符，将小写字符转换为大写字符，放入到buffer2</li>
<li>消费者从buffer2取出字符，将其打印到屏幕上</li>
</ul>

<h2>pc2.c: 使用信号量解决生产者、计算者、消费者问题</h2>
<ul>
<li>功能和前面的实验相同，使用信号量解决</li>
</ul>

<h2>ring.c: 创建N个线程，它们构成一个环</h2>
<ul>
<li>创建N个线程：T1、T2、T3、… TN</li>
<li>T1向T2发送整数1</li>
<li>T2收到后将整数加1</li>
<li>T2向T3发送整数2</li>
<li>T3收到后将整数加1</li>
<li>T3向T4发送整数3</li>
<li>…</li>
<li>TN收到后将整数加1</li>
<li>TN向T1发送整数N</li>
</ul>
</body></html>

