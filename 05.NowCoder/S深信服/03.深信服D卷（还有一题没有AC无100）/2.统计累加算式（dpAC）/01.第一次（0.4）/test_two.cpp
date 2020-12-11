#include<cstdio>
int solution[10];

int test(int n)
{
	for(int i=0;i<10;i++)
	{
		if(solution[i]==n)
		{
			return 1;
		}
	}
	
	return 0;
	
}

int main()
{
	int n;
	
	
	for(int i=0;i<10;i++)
	{
		unsigned int t=1;
		solution[i]=t<<i;
	}
	
	scanf("%d",&n);
	
	if(test(n))
	{
		printf("%d",n);
	}
	else
	{
		printf("%d",n-1);
	}

	
	return 0;
}

