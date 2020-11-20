

# cmd用for循创建数据

```txt
for /l %i in (1,1,999) echo %i >>test.txt
```


## 一、批量生成Markdown文件

```bat
@echo off
echo 正在创建B0.txt~test9.txt共十个文本文件......

for /l %%i in (1001, 1, 1095) do (
echo 我是PAT的B%%i.md题 >> B%%i.md
)
echo 文件创建完毕
```
