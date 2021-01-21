

# OJ多组输入输出总结

## 零、C++中string和字符数组的快速互换
受到C语言中`sscanf`和`sprintf`的启发


### 1）将string类型转换为字符数组

方法1）用string类的成员函数copy
注意，其实，C语言输入输出和C++输入输出，最好不要混合输入输出，我这样写只是为了论证这样可以
```cpp
#include<iostream>
#include<string> 
#include<cstring> 
using namespace std;

int main()
{
	
	while(1)
	{
		string str;
		cin>>str;
		char test[10]; 
		memset(test,-1,sizeof(test));
		//上面的memset是我故意，用来让自己注意
		//string转换到字符数组后，末尾的'\0'要手动加，不然就不行
		 
		
		str.copy(test,str.size());
		test[str.size()]='\0';
		 
		printf("%s\n",test);
	} 
	return 0;
} 
```

方法2）strcpy
```cpp
#include<iostream>
#include<string> 
#include<cstring> 
using namespace std;

int main()
{
	
	while(1)
	{
		string str;
		cin>>str;
		char test[10]; 
		memset(test,-1,sizeof(test));
		//上面的memset是我故意，告诉我们这样就不用管这些 
		
		strcpy(test,str.c_str()); 
		 
		printf("%s\n",test);
	} 
	return 0;
} 
```



### 2）字符数组转化成string类型
```cpp
#include<iostream>
#include<string> 
#include<cstring> 
using namespace std;

int main()
{
	char test[10];
	while(~scanf("%s",test))
	{
		
		string str;
		str=test;//字符数组转换为string 
		
		printf("%s\n",str.c_str());
	} 
	return 0;
} 
```

另一种用构造函数写的，但是有坑，那就是只能在构造的时候，初始化时
```cpp
#include<iostream>
#include<string> 
#include<cstring> 
using namespace std;

int main()
{
	char test[10];
	while(~scanf("%s",test))
	{
		
		string str(test);//注意——只能在初始化的时候，字符数组转换为string 
		
		//注意——下面这种方式不准！！ 
//		string str;
//		str(test);
		
		printf("%s\n",str.c_str());
	} 
	return 0;
} 
```

## 一、纯C++语言版本（不准用C语言版本）
为了能够熟练的使用`C++`的STL  
由于自己熟练C语言的字符数组，思维方式快成纯C语言的了，但是这些很影响刷OJ做题的速度。  
所以，打算，使用`C++`中的`String`代替字符数组  
弃用字符数组。  

原因
```txt
比如字符查找，我就可以懒得写了
字符匹配，也懒得写
```

### 1）整型数据
```cpp
#include<iostream>
using namespace std;

int main()
{
	int a,b;
	
	while(cin>>a>>b)
	{
		cout<<a+b<<endl;
	}
	return 0;
} 
```

#### 严格的
这样的格式
```txt
3,6
```

//cin.get()使用比较难讲，不要赖用
```cpp
#include<iostream>
using namespace std;

int main()
{
	int a,b;
	char c;
	while((cin>>a)&&(c=cin.get())&&(cin>>b))
	{
		cout<<a+b<<endl;
        cout.put(c);
	}
	return 0;
} 
```

### 2）字符数组（C++中用string类——自己不准自己用字符数组）
注意，这种输入，下面这样的数据，注意也用这组数据测试3）
```txt
asdad asdsa
```
```cpp
#include<iostream>
#include<string> 
using namespace std;

int main()
{
	string str;
	while(cin>>str)
	{
		cout<<str<<endl;
	}
	
	return 0;
} 
```

### 3）字符数组（C++中用string类）两个-用空格分开

```cpp
#include<iostream>
#include<string> 
using namespace std;

int main()
{
	string one;
	string two;
	while(cin>>one>>two)
	{
		cout<<one<<endl;
		cout<<two<<endl;
	}
	
	return 0;
} 
```

### 4）整行字符(string)，包括空格
```cpp
#include<iostream>
#include<string> 
using namespace std;

int main()
{
	string one;
	string two;
	//未考查下面这种多组输入 
	while(getline(cin,one))
	{
		cout<<one<<endl;
		
	}
	
	return 0;
} 
```




## 二、纯C语言版本

### 0）单个字符

### 1）整型数据
```c
#include<stdio.h>

int main()
{
	long long int a,b;
	while(~scanf("%lld%lld",&a,&b)) 
	{
		printf("%lld\n",a+b);
	}
	return 0;
}
```



### 2）字符数组
```c
#include<stdio.h>

int main()
{
	char test[100];
	while(~scanf("%s",test)) 
	{
		printf("%s\n",test);
	}
	return 0;
}
```



### 3）字符数组两个-用空格分开
```txt
aa ss
```

```c
#include<stdio.h>

int main()
{
	char one[100];
	char two[100];
	
	while(~scanf("%s%s",one,two)) 
	{
		printf("%s 中间加上我 %s\n",one,two);
	}
	return 0;
}
```



### 4）整行字符，包括空格
```c
#include<stdio.h>

int main()
{
	char test[100];
	
	while(NULL!=gets(test)) 
	{
		printf("%s\n",test);
	}
	return 0;
}
```







## 三、Java版本

//我自己配置的notepad++的java环境的，快捷键是F6就可以调用`插件NppExec`
Java在很多OJ  
<font style="background: yellow">1）只能使用 Main 作为主类名 </font> 
<font style="background: yellow">2）代码中必须存在一个public class Main。不允许出现其他的public class。 </font> 
牛客上还规定：

```txt
JAVA，注意类名必须为Main, 不要有任何package xxx信息
注意hasNext和hasNextLine的区别
```

附上[OJ中提交Java程序的一些套路](https://blog.csdn.net/bat67/article/details/79685997)
[Java：OJ中常用的各种输入](https://blog.csdn.net/da_kao_la/article/details/80225003)

### 1）整型数据
```java
import java.util.Scanner;
public class Main
{
	//只能保存为Main.java
    public static void main(String[] args)
	{
        Scanner in = new Scanner(System.in);

        while (in.hasNextInt())
		{
			//注意while处理多个case
            int a = in.nextInt();
            int b = in.nextInt();
            System.out.println(a + b);
        }

    }
}
```





