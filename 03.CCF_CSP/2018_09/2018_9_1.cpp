#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	int b[n]={0};
	b[0]=(a[1]+a[0])/2;
	b[n-1]=(a[n-1]+a[n-2])/2;
	for(int i=1;i<(n-1);i++)
	{
		b[i]=(a[i-1]+a[i+1]+a[i])/3;
	}
		for(int i=0;i<n;i++)
	{
		printf("%d",b[i]);
		if(i!=(n-1))
		{
			printf(" ");
		}
	}
	
	return 0;
 } 
