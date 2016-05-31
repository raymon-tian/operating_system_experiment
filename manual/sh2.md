<head>
<title>Shell第2版</title>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
</head>

# Shell第2版
## API参考
- [dup](api/dup.html)
- [dup2](api/dup.html)

## 例子
- [dup1](shell/dup1.c)
- [dup2](shell/dup2.c)

## 题目
- sh2.c: 实现shell程序，要求在第1版的基础上，添加如下功能
    + 实现文件重定向
    <pre>
      $ echo hello &gt;log
      $ cat log
      hello
    </pre>
