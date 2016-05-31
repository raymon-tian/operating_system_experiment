<head>
<title>Linux编程环境</title>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
</head>

# Linux编程环境
## 虚拟机
1. 登陆用户名：student，密码：student

2. 登陆后请运行register程序
    - 初始状态下，student用户没有执行编辑器vi、编译器cc的权限，不具备完成实验的条件
    - 运行register程序, 用户输入学号、姓名（汉语拼音)，示例如下：
        <pre>
        $ register
        Enter your student no: 0406101
        Enter your name: zhang san
        </pre>
    - register程序将把学号、姓名等信息记录到系统中，每次开机后会显示该台机器所有者的学号和姓名。
    - register程序赋予student用户执行编辑器vi、编译器cc的权限。
    - register程序删除自身，因此该程序只能运行一次。 
    - 为了方便管理和验收，请在/home/student目录下为每个实验创建一个单独的目录，目录的名称请见实验列表

3. 注意
    - 只有当你的学号和虚拟机中保存的信息一致，才可以请求验收作业。
    - 将需要完成的程序源文件放在/home/student/submit目录下
    - 已经在/home/student/submit目录下，为你创建好空的源文件
    - 不要改变源文件名称

4. 关闭虚拟机
    - 不要通过关闭windows窗口的方式，关闭虚拟机
    - 在linux中使用reboot命令关闭虚拟机 
    - 如果程序死循环，可以使用Ctrl-C中止程序的运行
    - 平时请注意备份自己的虚拟机

## Shell及常用命令
- [Unix Shell 介绍](ref/shell.html)
- ls命令
- pwd命令
- cd命令
- echo命令
- cat命令
- cp命令
- rm命令
- mv命令

## vi命令
<table border=1 cellspacing=0 cellpadding=4>
<tr>
  <td colspan=2>模式转换</td>
</tr>
<tr>
  <td>i</td>
  <td>进入插入模式, 在当前光标处插入</td>
</tr>
<tr>
  <td>a</td>
  <td>进入插入模式, 在当前光标后插入</td>
</tr>
<tr>
  <td>I</td>
  <td>进入插入模式, 在行首处插入</td>
</tr>
<tr>
  <td>A</td>
  <td>进入插入模式, 在行尾处插入</td>
</tr>
<tr>
  <td>ESC</td>
  <td>进入命令模式</td>
</tr>

<tr>
  <td colspan=2>移动光标</td>
</tr>
<tr>
  <td>h</td>
  <td>向左</td>
</tr>
<tr>
  <td>j</td>
  <td>向下</td>
</tr>
<tr>
  <td>k</td>
  <td>向上</td>
</tr>
<tr>
  <td>l</td>
  <td>向右</td>
</tr>

<tr>
  <td colspan=2>快速移动</td>
</tr>
<tr>
  <td>w</td>
  <td>向右移动一个单词</td>
</tr>
<tr>
  <td>b</td>
  <td>向左移动一个单词</td>
</tr>
<tr>
  <td>Ctrl-D</td>
  <td>向下移动半页</td>
</tr>
<tr>
  <td>Ctrl-U</td>
  <td>向上移动半页</td>
</tr>
<tr>
  <td>^</td>
  <td>移动到行首</td>
</tr>
<tr>
  <td>$</td>
  <td>移动到行尾</td>
</tr>

<tr>
  <td colspan=2>删除</td>
</tr>
<tr>
  <td>x</td>
  <td>删除一个字符</td>
</tr>
<tr>
  <td>dw</td>
  <td>删除一个单词</td>
</tr>
<tr>
  <td>dd</td>
  <td>删除一行</td>
</tr>
<tr>
  <td>u</td>
  <td>撤销上一次操作</td>
</tr>

<tr>
  <td colspan=2>文件操作</td>
</tr>
<tr>
  <td>:w</td>
  <td>保存</td>
</tr>
<tr>
  <td>:w file</td>
  <td>保存为</td>
</tr>
<tr>
  <td>:q</td>
  <td>退出</td>
</tr>
<tr>
  <td>:wq</td>
  <td>保存退出</td>
</tr>
<tr>
  <td>:q!</td>
  <td>不保存退出</td>
</tr>

</table>

## vi参考
- [学习vi备忘](https://www.gentoo.org/doc/zh_cn/vi-guide.xml)
- [使用vi编辑文件](https://www.ibm.com/developerworks/cn/linux/l-lpic1-v3-103-8/)
- [简明Vim练级攻略](http://coolshell.cn/articles/5426.html)

## 参考书
[<<UNIX环境高级编程>>](http://product.china-pub.com/3770189)

《UNIX环境高级编程(第3版)》是被誉为UNIX编程“圣经”的Advanced Programming in the UNIX Environment一书的第3版。本书介绍UNIX文件和目录、标准I/O库、系统数据文件和信息、进程环境、进程控制、进程关系、信号、线程、线程控制、守护进程、各种I/O、进程间通信、网络IPC、伪终端等方面的内容。

[<<鸟哥的Linux私房菜.基础学习篇>>](http://product.china-pub.com/51609)

本书是最具知名度的Linux入门书《鸟哥的Linux私房菜基础学习篇》的最新版，
全面而详细地介绍了Linux操作系统。 全书分为5个部分：<br>
1. 说明Linux的起源及功能，如何规划和安装Linux主机；<br>
2. 介绍Linux的文件系统、文件、目录与磁盘的管理；<br>
3. 介绍文字模式接口shell和管理系统的好帮手shell脚本，另外还介绍了文字编辑器vi和vim的使用方法；<br>
4. 介绍了对于系统安全非常重要的Linux账号的管理，以及主机系统与程序的管理，如查看进程、任务分配和作业管理；<br>
5. 介绍了系统管理员(root)的管理事项，如了解系统运行状况、系统服务，针对登录文件进行解析，对系统进行备份以及核心的管理等。<br>
