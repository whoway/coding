#include<iostream>
#include<cstdio>
#include<algorithm> 
using namespace std;
int main()
{
	int n=10,m=10;
	char aa[n][m];
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			aa[i][j]='.';	
		}
		
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(j!=(m-1))
			printf("%c ",aa[i][j]);
			else
			printf("%c",aa[i][j]);		
		}
		
		if(i!=(n-1))
		printf("\n");
		
	}
	
	
	return 0;
}

//看来这种	char aa[n][m]={'.'};、
//给多维数组赋值的方式不行，必须考虑用其他的 
/// 暂时不知道，所以就用for循环初始化了它 
