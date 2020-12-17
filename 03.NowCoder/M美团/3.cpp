#include<bits/stdc++.h>
using namespace std;

char one[55];
char two[55];

//以i结尾的最长连续的序列的长度 
int dp[55];
int solve(int lenOne,int lenTwo)
{
	int rt=0;
	
	int MAX=max(lenOne,lenTwo);
	if(MAX==lenOne)
	{
		
		
		int tt=lenOne-lenTwo;
		//one开始的 
		for(int i=0;i<=tt;++i) 
		{
			int tag=0;//第1个还没有处理 
			
			int index=i;
			for(int j=0;j<lenTwo;++j)
			{
				if(0==tag)
				{
					if(one[index++]==two[j])
					{
						dp[0]=1;
						rt=max(rt,dp[0]);
					}
					else
					{
						dp[0]=0;
					}
					tag=1;
				}
				else
				{
					if(one[index++]==two[j])
					{
						dp[j]=dp[j-1]+1;
						rt=max(rt,dp[j]);
					}
					else
					{
						dp[j]=0;
					}
				}
			}
		}
	}
	else
	{
		//第2个更长—————————— 
		int tt=lenTwo-lenOne;
		
		//Two开始的 
		for(int i=0;i<=tt;++i) 
		{
			int tag=0;//第1个还没有处理 
			
			int index=i;
			for(int j=0;j<lenOne;++j)
			{
				if(0==tag)
				{
					if(one[j]==two[index++])
					{
						dp[0]=1;
						rt=max(rt,dp[0]);
					}
					else
					{
						dp[0]=0;
					}
					tag=1;
				}
				else
				{
					if(one[j]==two[index++])
					{
						dp[j]=dp[j-1]+1;
						rt=max(rt,dp[j]);
					}
					else
					{
						dp[j]=0;
					}
				}
			}
		}
	}
	
	
	return rt;
}





int main()
{
	while(NULL!=gets(one))
	{
		gets(two);
		
		int lenOne=strlen(one);
		int lenTwo=strlen(two);
		if(lenOne==1 && 1==lenTwo)
		{
			if(one[0]==two[0])
			{
				printf("1\n");
			}
			else
			{
				printf("0\n");
			}
		}
		else
		{
			int num=solve(lenOne,lenTwo);
			printf("%d\n",num);
		}
	}
	return 0;
 } 
