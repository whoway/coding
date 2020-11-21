#include<iostream>
#include<cstdio>
#include<algorithm> 

using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	int test[1000]={0};
	int aa[n]; 
	for(int i=0;i<n;i++)
	{
		scanf("%d",&aa[i]);
		test[aa[i]]++;
	}
	
	return 0;
}
