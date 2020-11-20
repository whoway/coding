#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int num;
	int a[1001]={0};
	for(int i=0;i<n;i++)
	{
		scanf("%d",&num);
		if(num>0)
		{
			a[num]++;
		}
		else
		{
			a[-num]++;
		}
	}
	int sum=0;
	for(int i=1;i<1001;i++)
	{
		if(a[i]==2)
		{
			sum++;
		}
	}
	printf("%d",sum);
	return 0;
 } 
