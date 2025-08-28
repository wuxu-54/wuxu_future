#!/usr/bin/python3
# -*- coding: UTF-8 -*-

from io import open
import chardet
import random

xing=[]
ming=[]

# 打开姓文件
with open('./name.txt', 'r', encoding='utf-8') as file:
    while True:
        content = file.read(1)
        if content == '\n':
            continue
        if not content:
            break
        else:
            xing.append(content)

print(xing)


# 打开名文件
with open('./ming.txt', 'r', encoding='utf-8') as file:
    while True:
        content = file.readline().replace('\n',"")
        if not content:
            break
        else:
            ming.append(content)

print(ming)


#随机组合姓名
random_names = [random.choice(xing) + random.choice(ming) for _ in range(1000)]

for name in random_names[:1000]:
    print(name)

#将名字写入到out.txt中
with open('./out.txt','w',encoding='utf-8') as writeFile:
    for name in random_names[:1000]:
        writeFile.write(name+'\n')