# Python

学习地址：[菜鸟教程-python3](https://www.runoob.com/python3/python3-tutorial.html)

笔记基于python3。

## 笔记

### 语法记录

- `not all(char in punctuation for char in word))`:这是 生成器表达式 配合 内置函数 all() 的用法
  1. char in punctuation for char in word：生成器表达式，逐个检查 word 中的字符是否在 punctuation 中，产生布尔值序列。
  2. all(...)：当序列中所有值都为 True 时返回 True（即判断是否“全是标点”）。
  3. not：取反，实现“不全是标点”的逻辑过滤。
