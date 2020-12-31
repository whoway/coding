

# PAT测试系统说明

## 注意：

1.PAT上数据比牛客上严格  
2.PAT上2020年有一些题目的边界数据的增加，有的教程上代码无法AC了  





## PAT编译器上的坑  
>- 1）PAT的这两个`C++`编译器(`C++ gcc6.5.0`和`C++ clang++ 6.0.1`）都不支持`gets()`
要是你的C++代码中出现了，就会导致（似乎原因是什么不安全...）  
```txt
a.cpp: In function ‘int main()’:
a.cpp:12:11: error: ‘gets’ was not declared in this scope
  gets(str1);
```
>>- 解决方式：
使用 iostream库中的`cin.getline`函数代替gets

```cpp
/* 读入一行（可含空格），直到换行符结束
 * 将其前num-1个字符存入数组a中并以字符c结尾 */
cin.getline(a, num, c);
解决方式：
使用 iostream 库中的cin.getline函数代替gets
tips：
1、也可以不传入第三个参数c，则默认 '\0' 结尾
2、若num大于所读入的字符数，则直接存入整行字符串，再在末尾加入字符c结尾
```



>- 2）PAT上面的C语言编译器支持`gets()`（可以用C语言编译器），如果你不想用`C++`的STL的话。  






















