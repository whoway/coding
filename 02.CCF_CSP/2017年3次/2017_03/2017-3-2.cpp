#include<cstdio>

int main()
{
	int n,m;
	scanf("%d",&n);
	scanf("%d",&m);
	int aa[n+1]={0};
	for(int ii=1;ii<=n;ii++)
	{
		aa[ii]=ii;
	}
	int a,b,ii,jj;

	
	for(int k=0;k<m;k++)
	{
		scanf("%d%d",&a,&b);
		b=-b;
		if(b>0)
		{
			for(int i=1;i<(n+1);i++)
			{
				if(aa[i]==a)
				{
					ii=i;
					break;
				}
			
			}
		int s=a;
			for(int num=ii;num>(ii-b);num--)
			{
				aa[num]=aa[num-1];
			}
		aa[ii-b]=s;
				
		}
		else if(b<0)
		{
			for(int j=1;j<(n+1);j++)
			{
				if(aa[j]==a)
				{
					jj=j;
					break;
				}
			
			}
		int ss=a;
			for(int num=jj;num<(jj-b);num++)
			{
				aa[num]=aa[num+1];
			}
		aa[jj-b]=ss;
			
		}
		
	}
	
	for(int d=1;d<(n+1);d++)
	{
		if(d!=n)
		printf("%d ",aa[d]);
		else
		printf("%d",aa[d]);
	}
	
	

	return 0;
}
