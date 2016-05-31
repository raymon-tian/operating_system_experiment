<head>
<title>Shell第1版</title>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
</head>

# Shell第1版
## API参考
- [chdir](api/chdir.html)

## 例子
- [chdir](shell/chdir.c)

## 题目
- sh1.c: 实现shell程序，要求具备如下功能
    + 支持命令参数
    <pre>
    $ echo arg1 arg2 arg3
    $ ls /bin /usr/bin /home
    </pre>

    + 实现内置命令cd、pwd、exit 
    <pre>
    $ cd /bin
    $ pwd
    /bin
    </pre>
