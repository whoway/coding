#include<iostream>
#include<cstdio>
using namespace std;
int is(int a);
int main()
{
	int n;
	int s;
	scanf("%d",&n);
	for(int i=100;i<=100000;i+=100)
	{
		s=is(i);
		if(s==n)
		{
			printf("%d",i);
			break;
		}
	}
	
	return 0;
}

int is(int a)
{
	int num,k;
	if(a<=3500)
	{
		return a;
	}
	else
	{
		num=a-3500;
		if(num<=1500)
		{

			k=3500+num*0.97;
		}
		else if(num<=4500)
		{
			num-=1500;//qian
			k=3500+1500*0.97+num*0.9;
		}
		else if(num<=9000)
		{
			num=num-4500;
			k=3500+1500*0.97+3000*0.9+num*0.8;
		}					//qianmian  2 tiapojian 
		else if(num<=35000)
		{
			num-=9000;
			k=3500+1500*0.97+3000*0.9+4500*0.8+num*0.75;
		}
		else if(num<=55000)
		{
			num-=35000;
			k=3500+1500*0.97+3000*0.9+4500*0.8+26000*0.75+num*0.7;
		}
		else if(num<=80000)
		{
			num-=55000;
			k=3500+1500*0.97+3000*0.9+4500*0.8+26000*0.75+20000*0.7+num*0.65;
		}
		else 
		{
			num-=80000;
			k=3500+1500*0.97+3000*0.9+4500*0.8+26000*0.75+20000*0.7+num*0.65;
		}
		
		return k;
	}
	
	
}
