#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int n,k,num=0;
	scanf("%d",&n);
	scanf("%d",&k);
	int aa[n+1]={1};
	int bb[n+1]={2};
	
	int i=1,kk=1;
	
	
	while(1)
	{
		
		if(i>n)
		{
			i=1;
			if(aa[i]==1)
			{
				if(kk%k==0||(kk-k)%10==0)
				aa[i]=2;
				
				i++;
				kk++;
			}
			else
			{
				for(int s=i;s<=n;s++)
			{
				if(aa[s]==1)
				{
					i=s;
					break;
				}
			}
			
			if(kk%k==0||(kk-k)%10==0)
			aa[i]=2;
			
				i++;
				kk++;		
			}
					
		}
		else if(aa[i]==1)
		{
			if(kk%k==0||(kk-k)%10==0)
			aa[i]=2;
			
				i++;
				kk++;	
		}
		else
		{
			for(int s=i;s<=n;s++)
			{
				if(aa[s]==1)
				{
					i=s;
					break;
				}
			}
			if(kk%k==0||(kk-k)%10==0)
			aa[i]=2;
			
				i++;
				kk++;	
		}

		
		for(int j=1;j<(n+1);j++)
		{
			bb[j]=aa[j];
		}	
		
		sort(bb,bb+(n+1));
		
		if(bb[2]==2)
		{
			for(int s=1;s<=n;s++)
			{
				if(aa[s]==1)
				{
					num=s;
					printf("%d",num);
					break;
				}
			}	
			break;
		}
	
	}

	return 0;
 } 
