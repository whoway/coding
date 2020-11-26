#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	int a[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	int sum=0,human=0;
	for(int i=0;i<n;i++)
	{
		sum=sum+a[i];
		if(i==(n-1))
		{
			human++;
		}
		else if(sum>=k)
		{
			human++;
			sum=0;
		}
	}
	printf("%d",human);
	return 0;
}
