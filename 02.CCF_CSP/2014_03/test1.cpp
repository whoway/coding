#include<cstdio>

int is(int aa[][5],int num)
{
	int i=0;
	int t;
	while(1)
	{
		if(aa[i][0]==num)
		{
			t=i;
			break;
		}
		else
		i++;
	}
	return t;
}


int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int aa[n][5];
	int bb[m][2];
	int out[m];
	
	for(int i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&aa[i][1],&aa[i][2],&aa[i][3],&aa[i][4]);
		aa[i][0]=n-i;
	}
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&bb[i][0],&bb[i][1]);
	}
	
	int test=0;
	int f;
	for(int i=0;i<m;i++)
	{
		for(int num=1;num<=n;num++)
		{
			f=is(aa,num);
			if((aa[i][3]>=bb[i][0]>=aa[i][1])&&(aa[i][2]<=bb[i]<=aa[i][4])) 
			{
				test=f;
				break;
			}
		}
		
		if(test==0)
		{
			out[i]=0;
		}
		else
		{
			out[i]=test;///这个附近的算法有点错 
		}
		
		
		
	}
	
	
	
	
	
	return 0;
}

///这个的算法有点错 ，鉴于时间未修改； 

