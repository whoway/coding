#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int aa[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&aa[i]);
	}
	
	int max=abs(aa[1]-aa[0]);//60在于这儿那个-号被我刚开始错写为了=号 
	
	for(int i=1;i<(n-1);i++)
	{
		if(abs(aa[i+1]-aa[i])>max)
		{
			max=abs(aa[i+1]-aa[i]);
		}
	}
	printf("%d",max);
	
	return 0;
 } 
