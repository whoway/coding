#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	char a[13];
	int b[13]={0};
	char c;
	for(int i=0;i<13;i++)
	{
		scanf("%c",&a[i]);
		if(a[i]!='-')
		{
			c=a[i];
			b[i]=(int)c-48;//解决了强制类型转换，因为字符0-9对应的ASCII码为48-57 
		}
	}
	int sum=0;
	int j=1;
	int num;
	for(int i=0;i<12;i++)
	{
		if(a[i]!='-')
		{
			sum=sum+b[i]*j;
			++j;
		}
	}
	
	int k;
	k=sum%11;
	char cc='n';
	if(k==10)
	{
		cc='X';
	}
	
	if(k==(int)a[12]-48)
	{
		printf("Right");
	}
	else if(cc==a[12])
	{
		printf("Right");//判别为X的情况 
	}
	else
	{
//		for(int i=0;i<12;i++)
//		{
//		printf("%c",a[i]);
//		}
//		printf("%c",(char)(k+48));
		for(int i=0;i<12;i++)
	{
		if(a[i]!='-')
		{
		printf("%d",b[i]);
		}
		else
		printf("%c",a[i]);
	}
	
	if(k==10)
	{
		printf("%c",cc);
	}
	else
	printf("%d",k);
	}	
	return 0;
}



/*解题报告 
 题型：
 简单模拟题（情况比第一题多，格式需要注意） 
 
 注意点+工具： 
 1.碰到的问题是“char类型怎么变成int类型” 
 2.碰到的问题是“ISBN码包括9位数字”中输出格式不对，所以不能满分！！ 
 3.如果余数为10，则识别码为大写字母X，该情况的讨论不全，也导致不是满分！ 
  
 
 思路：
 1）本方法为直接模拟 

 */
