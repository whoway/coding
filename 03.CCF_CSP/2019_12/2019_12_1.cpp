#include<iostream>
#include<cstdio>
using namespace std;

int test(int k)
{
	int a;
	if(k%7==0)
	return 1;
	
	a=k%10;
	if(a==7)
	return 1;
	
	while(k/=10)
	{
		a=k%10;
		if(a==7)
		return 1;
	}	
	return 0;	
}



int main()
{
	
	int num,out[5]={0};
	scanf("%d",&num);
	int s=1;
	for(int i=0;i<num;s++)
	{
		if(test(s))
		out[(s%4)]++;
		else
		{
			i++;
		}
			
	}
	
	for(int j=1;j<4;j++)
	{
		printf("%d",out[j]);
		printf("\n");
	}
		printf("%d",out[0]);
	
	
 } 
