## 1001 A+B Format (20分)

一、思路和难点



二、代码（别人的）

```cpp
#include <iostream>
#include <stack>
using namespace std;
int main()
{
    stack <int> s;
    long int a,b,x;
    int bool_1=0;
    int j=0,k=0;
    cin>>a>>b;
    x=a+b;

   if(x==0)
   {
       cout<<x;
       return 0;
   }
    
    if(x<0)
    {
        x=x*(-1);
        bool_1=1;
    }
    while(x)
    {
        s.push(x%10);
        x/=10;
        j++;
    }
    while (!s.empty())
    {
        if(bool_1==1)
        {
              cout<<'-';
              bool_1=0;
        }
        j--;
        cout<<s.top();
        s.pop();

        if(j%3==0&&j!=0)
            cout<<',';
    }
    return 0;
}
```













## A1042	Shuffling Machine

```cpp
#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm> 
using namespace std;

struct node{
	char c;
	int num;
	int x;//表示当前位置
	 
}test[54]; 

bool cmp(node a,node b) 
{
	return a.x<b.x;//按照x的值，从小到大 
}


int kk[54];

int main()
{

	int s=0;//表示，第几个数字
	 
	for(int j=1;s<13;s++,j++)
	{
		test[s].c='S';
		test[s].num=j;
		test[s].x=s;
	}
	
	for(int j=1;s<26;s++,j++)
	{
		test[s].c='H';
		test[s].num=j;
		test[s].x=s;
	}
	
	for(int j=1;s<39;s++,j++)
	{
		test[s].c='C';
		test[s].num=j;
		test[s].x=s;
	}
	
	for(int j=1;s<52;s++,j++)
	{
		test[s].c='D';
		test[s].num=j;
		test[s].x=s;
	}
	
	for(int j=1;s<54;s++,j++)
	{
		test[s].c='J';
		test[s].num=j;
		test[s].x=s;
	}
	
	
	int n;
	scanf("%d",&n);
	
	for(int i=0;i<54;i++)
	{
		scanf("%d",&kk[i]);
	}
	
	for(int i=0;i<n;i++)
	{
		
		for(int j=0;j<54;j++)
		{
			test[j].x=kk[j];
		}
		sort(test,test+54,cmp);
	}
	
	
	for(int j=0;j<53;j++)
	{
		printf("%c%d ",test[j].c,test[j].num);
	}
	printf("%c%d",test[53].c,test[53].num);
	
	return 0;
 } 
```













## A 1046	Shortest Distance



```cpp
//#include<iostream>
#include<cstdio>

//using namespace std;

//int lowbit(int x)
//{
//	return x&(-x);
//}
//
//int getSum(int x,int c[])
//{
//	int sum_temp=0;
//	for(int i=x;i>0;i-=lowbit(i))
//	{
//		sum_temp+=c[i] ;
//	}
//	
//	return sum_temp;
//}





int main()
{
	int sum=0;
	int n;
	scanf("%d",&n);
	
	int test[n];//存响铃的 
	int bit[n];//he，1表示。。。
	 
	for(int i=1;i<n;i++)
	{
		scanf("%d",&test[i]);
		sum+=test[i];
		bit[i]=sum;
	}
	scanf("%d",&test[0]);
	sum+=test[0];
	
	
	
	
	
	int one;
	scanf("%d",&one);
	
	int out[one];//shuch 
	
	int a,b;
	int num=0;
	for(int i=0;i<one;i++)
	{
		scanf("%d%d",&a,&b);
		
		int temp=a;
		if(a>b)
		{
			a=b;
			b=temp;
		}
		
		if((b-a==1)&&(a==1))
		num=bit[1];
		else if((b-a==1)&&(a!=1))
		num=bit[a]-bit[a-1];
		else if((a==1)&&(b-a)>1)
		num=bit[b-1];
		else
		num=bit[b-1]-bit[a-1];
//		for(int jj=a;jj<b;jj++)
//		{
//			num+=test[jj];
//		}
		
		if(num<(sum-num))
		out[i]=num;
		else
		out[i]=sum-num;
		
		num=0;
	}
	
	
	for(int i=0;i<one-1;i++)
	{
		printf("%d\n",out[i]);
	}
		printf("%d",out[one-1]);
		
		
	
	return 0;
 } 
```





## A1065	A+B and C (64bit)（很又有的技巧，判断64位的溢出）

技巧：判断long long相加和相减的溢出，技巧

《计算机组成原理》中指出，如何两个正数之和等于负数，或者两个负数之和等于正数，就是溢出。

我们需要考虑，两个整数相加所会导致的正溢出或者负溢出

```cpp
#include<cstdio>

int out[11]={0};

int test(long long a,long long b,long long c)
{
	//1表示true 
	long long t=a+b;
	 
	if((a>0)&&(b>0)&&(t<=0))
	{
		//相加太大的溢出 
		return 1; 
	}
	else if((a<0)&&(b<0)&&(t>=0))
	{
		//两个负数相加的溢出
		return 0; 
	}
	else if(t>c)
	return 1;
	else
	return 0;
	
 } 

int main()
{
	int n;
	scanf("%d",&n);
	
	long long a,b,c;
	
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld%lld",&a,&b,&c);
		out[i]=test(a,b,c);
	}
	
	int i=1;
	for(;i<n;i++)
	{
		if(out[i])
		printf("Case #%d: true\n",i);
		else
		printf("Case #%d: false\n",i);
	}
	
	if(out[i])
	printf("Case #%d: true",i);
	else
	printf("Case #%d: false",i);
	
	
	return 0;
 } 
```











