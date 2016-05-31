<head>
<title>malloc</title>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
</head>

# 内存分配算法: malloc
## API参考
- [malloc](api/malloc.html)
- [free](api/free.html)

## 测试用例 
- [测试用例](malloc/test.c)
- [框架程序](arch/malloc.c)

## 题目
- malloc.c: 编写my_malloc/my_free函数
    + 功能与malloc/free相同
    + 基于首次适应算法 
    + 释放内存块时候，能够对相邻空闲内存块进行合并
    + 使用my_malloc替换malloc，能够通过上述测试用例
    + 实现print_free_memory，打印当前空闲内存数目，检查它的输出是否正常
