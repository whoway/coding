#include<cstdio>

int main()
{
	int n;
	scanf("%d",&n);
	int aa[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&aa[i]);
	}
	int sum=0;
	for(int i=0;i<(n-1);i++)
	{
		if(aa[i]!=aa[i+1])
		sum++;
	}
	sum++;
	printf("%d",sum);
	
	return 0;
}
