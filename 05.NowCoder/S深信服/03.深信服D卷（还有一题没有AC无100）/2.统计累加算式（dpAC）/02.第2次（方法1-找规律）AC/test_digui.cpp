#include<cstdio>

int solution[1000+1];

int main()
{
	solution[1]=1;
	for(int i=2; i<=1000 ; ++i)
	{
		if(i&1) //ÆæÊý 
		{
			solution[i]=solution[i-1];
		}
		else
		{
			solution[i]=solution[i-1]+solution[i/2];
		}
		
	}
	
	int n;
	scanf("%d",&n);
	printf("%d",solution[n]);
	
}



