#include<cstdio>
#include<algorithm>
int main()
{
	int aa[1001]={0};
	int n,a;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a);
		aa[abs(a)]++;
	}
	
	int sum=0;
	for(int i=1;i<1001;i++)
	{
		if(aa[i]==2)
		sum++;
	}
	printf("%d",sum);
	
	return 0;
 } 
