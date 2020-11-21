#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

struct test{
	int x,y;
	int aa;//上下左右的个数，决定能不能建 
	int flag;//评分 
}test[1000+5];

int main()
{
	for(int i=0;i<1005;i++)
	{
		test[i].aa =0;
		test[i].flag =0;
	 } 
	int num;
	scanf("%d",&num);
	for(int i=0;i<num;i++)
	{
		scanf("%d%d",&(test[i].x),&(test[i].y));
	}
	
	for(int i=0;i<(num-1);i++)
	{
		for(int j=i+1;j<num;j++)
		{
			if(abs(test[i].x -test[j].x)==1)
			{
				if(abs(test[i].y -test[j].y)==1)
				{
					test[i].flag ++;
					test[j].flag ++;
				}
				else if(abs(test[i].y -test[j].y)==0)
				{
					test[i].aa ++;
					test[j].aa ++;
				}
			}
			
			
			if(abs(test[i].x -test[j].x)==0)
			{
				if(abs(test[i].y -test[j].y)==1)
				{
					test[i].aa ++;
					test[j].aa ++;
				}
			
			}
			
			
		}
	}
	
	
	int out[5]={0};
	for(int i=0;i<num;i++)
	{
		if(test[i].aa ==4)
		out[test[i].flag ]++;
		
	 } 
	
	for(int i=0;i<4;i++)
	{
		printf("%d\n",out[i]);
	}
	printf("%d",out[4]);
	
	
	
 } 
