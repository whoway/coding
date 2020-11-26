#include<iostream>
#include<cstdio>
using namespace std;
int test[2][1000+5]={0};

int main()
{
	int N,M;
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&test[i][0]);
		int sum=0,temp;
		for(int j=0;j<M;j++)
		{
			scanf("%d",&temp);
			sum+=temp;
		}
		test[i][1]=sum;
	}
	
	int aa=0,bb=0;
	 
	int min=0;//存放的是负数，蔬果最多的 
	for(int i=0;i<N;i++){
		if(test[i][1]<min)
		min=test[i][1];
		
		aa+=test[i][0]; 
		bb+=test[i][1];
	}
	int num=0;
	for(int i=0;i<N;i++)
	{
		if(test[i][1]==min)
		{
			num=i;
			break;
		}
	}
	num++;//输出是第几颗
	 
	printf("%d %d %d",(aa+bb),num,(-min));
	
	return 0;
}
