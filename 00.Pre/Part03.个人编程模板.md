# 个人编程模板





## 一、常量定义和变量名

```cpp
static const int maxn=1e5+5;
```

```txt
常用变量名：
loop  循环   
sentry哨兵
ret   返回值
res/result  结果
INF / MAXN / N   很大的值
odd   奇数 
even  偶数
exp  指数
cof  系数
poly 多项式
score 分数
```





## 二、格式化输出模板

```cpp
while( loop-- )
{
    printf("%d%c",solve[loop], loop?' ': '\n');
    //等价于printf("%d%c",solve[loop], loop?: 32 : 10);  
}
```





## 三、『四舍五入』模板

**1、printf的格式化输出**

`%3d`表示输出3位数，不满3位的高位补『空格』

`%03d`表示输出3位整数，不满3位的高位补『0』

**2、四舍五入『模板』**

- +0.5是精髓

```cpp
double num=3.5;
printf("%d\n",num);//直接截取
printf("%d\n", (int)(num+0.5));//四舍五入
```



```cpp
//num=(num*pow(10,2)+0.5)/pow(10,2);  
//注意，pow(10,需要保留的位数)
////如果采用『四舍五入』
		printf("第%d名选手的最好成绩为:%.2lf\n", (3-loop), num );


```



```cpp
#include<stdio.h>
#include<math.h>
#include<stdlib.h>


struct node
{
	double val[3];
} solve[3];


int main()
{



	//第（3-loop）个选手的成绩
	int loop=3;
	while( loop-- )
	{
		printf("请输入第%d名选手的三次成绩\n", (3-loop) );

		//输入第（tag+1）个成绩
		int tag=0;
		while( tag<3 )
		{
			//如果输入错误则要求强制重新输入
			while( 1 )
			{	
				double num;
				scanf("%lf",&num);
				if( (num-0.0)>0.0001 && (num-10.0)<0.0001 )
				{
					solve[loop].val[tag]=num;
					break;//关键之处：用while(1)和break的组合来弄出那样的效果
				}
				else
				{
					printf("输入错误,请重新输入！\n");
				}
			}//#end while( 1 )

			++tag;
		}//#end while( tag<3 )

			
	}//#end while( loop-- )


	loop=3;
	while( loop-- )
	{
		double num=solve[loop].val[0];
		int i=1;
		for(; i<3; ++i)
		{
			if( num<solve[loop].val[i] )
			{
				num=solve[loop].val[i];
			}
		}
		printf("第%d名选手的最好成绩为:%.2lf\n", (3-loop), num );

	}


	return 0;
}
```



**3、注意事项**

```cpp
%d 是直接将double第1位小数截取
%.1f是指将第二位小数直接去掉还是要四舍五入？
    答：%.1f (注意是1)对第二位小数，四舍五入！！
```

```txt
%.2lf竟然是四舍五入的！

以此留念。
```

```cpp
C语言printf函数%.2f输出为什么四舍五入实现机制不同？
```

知乎上[回答](https://www.zhihu.com/question/364159510)



## 四、判断某个整数奇/偶

```cpp
int n;
if( n&1 )
{
    //奇数
}
else
{
	//偶数
}
```

## 五、判断是否非0

```cp
int n;
if( n )
{
	//n=1，还有n=-1啥的
}
```



## 六、『逆向思维』编程技巧

反转反转，这种逆向思维，来自高中物理，在代码中也有用到

- 比如，大数加法

