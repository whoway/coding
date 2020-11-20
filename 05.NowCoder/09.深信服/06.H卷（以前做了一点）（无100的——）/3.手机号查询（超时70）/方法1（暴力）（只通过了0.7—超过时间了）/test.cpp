#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int maxn=15000;
const int num=100000;
char str[maxn][12];
int solution[num]={0};
int n,m;

int cmp(char temp[], int len, int row)
{
	int flag=0;//²»ÊÇ
	 
	for(int i=0; i<=(11-len) ;++i) 
	{
		int s=i;
		
		for(int j=0; j<len ; ++j) 
		{
			if(str[row][s]==temp[j])
			{
				s++;
			}
			else
			{
				break;
			}
			
		}
		
		if(s-i==len) 
		{
			return 1;
		}
		
	}
	
	return 0;
}



int main()
{
	
	scanf("%d%d",&n,&m);
	getchar();//×¢Òâ 
	for(int i=0; i<n ; ++i)
	{
		gets(str[i]);
//		printf("%s\n",str[i]);
	}
	
	char temp[12];
	int output=0;
	

	for(int i=0; i<m ; ++i)
	{
		
		int num_out=0;
		
		gets(temp);
		
		for(int j=0; j<n ;++j)
		{
			output=cmp(temp , strlen(temp), j);
			if(output)
			{
				num_out++;
			}
		}
		
		
		solution[i]=num_out;
		
	}
	
	
	for(int i=0; i<m ; ++i)
	{
		printf("%d\n",solution[i]);
	}

	
	return 0;
 } 
