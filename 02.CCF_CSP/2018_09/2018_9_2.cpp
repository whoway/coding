#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int a[10001]={0};
	int b[10001]={0};
	int num1=0,num2=0;
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&num1,&num2);
		for(int j=num1;j<=num2;j++)
		{
			a[j]=i+1;
		}
	}
	
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&num1,&num2);
		for(int j=num1;j<=num2;j++)
		{
			b[j]=i+1;
		}
	}
	int s=1,sum=0;
	int kk=0,ss=0;
	for(int i=1;i<10001;i++)
	{
		if(a[i]==s&&b[i]==s)
		{
			sum++;
			if(kk!=s)
			{
				ss++;
			}
			else{
				kk=s;
			}
		}
		else if(a[i]==(s+1)||b[i]==(s+1))
		{
			s++;
		}	
	}
	sum=sum-ss;
	printf("%d",sum);

	return 0;
 } 
 
 /*
 0分，
 第一次是因为&num2忘记写&了和数组可能开大了？
 后面也是数组可能开大了
 
 总的来说，他的那个 
 */
