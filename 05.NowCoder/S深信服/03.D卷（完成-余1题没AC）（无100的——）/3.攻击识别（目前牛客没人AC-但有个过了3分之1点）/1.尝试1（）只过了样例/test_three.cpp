#include<cstdio>
#include<cstring>


const int maxn=100000;
char solution[maxn][51];

int test(char *mode, char *p)
{
	int len_mode=strlen(mode);
	int len_p=strlen(p);
	
	if(len_p<len_mode)
	{
		return 0;
	} 
	
	if(mode[0]!=p[0])
	{
		return 0;
	}
	
	int one=0;
	for(int i=0; i<len_mode ; i++)
	{
		if(mode[i]==p[i])
		{
			one++;
		}
		else
		{
			break;
		}
	}
	
	int two=0;
	for(int i=0; i<len_mode ; i++)
	{
		if(mode[len_mode-1-i]==p[len_p-1-i])
		{
			two++;
		}
		else
		{
			break;
		}
	}
	
	if((len_mode==(one+two))&&(two!=0)&&(one!=0))
	{
		return 1;
	}
	else
	{
		return 0;
	}
	
}


int main()
{
	
	char temp[1000+1];
	
	int n;
	
	while(~scanf("%d",&n))
	{
		for(int i=0; i<n ;++i)
		{
			scanf("%s",&solution[i]);

		}
		
		int k;
		scanf("%d",&k);
		for(int i=0; i<k ;++i)
		{
			scanf("%s",temp);
			
			int flag=0;//±íÊ¾NO 
			for(int j=0; j<maxn; ++j)
			{
				if(test(solution[j] , temp))
				{
					flag=1;
					break;
				}
			}
			
			if(flag)
			{
				printf("YES\n");
			}
			else
			{
				printf("NO\n");
			}
			
		}
		
	}
	
	return 0;
}

