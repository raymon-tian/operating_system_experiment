<head>
<title>Shell第3版</title>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
</head>

# Shell第3版
## API参考
- [pipe](api/pipe.html)

## 例子
- [pipe1](shell/pipe1.c)
- [pipe2](shell/pipe2.c)
- [pipe3](shell/pipe3.c)
- [pipe4](shell/pipe4.c)

## 题目
- sh3.c: 实现shell程序，要求在第2版的基础上，添加如下功能
    - 实现管道
    <pre>
      $ cat /etc/passwd | wc -l
    </pre>

    - 实现管道和文件重定向 
    <pre>
      $ cat input.txt
      3
      2
      1
      3
      2
      1
      $ cat <input.txt | sort | uniq | cat >output.txt 
      $ cat output.txt
      1
      2
      3
    </pre>
