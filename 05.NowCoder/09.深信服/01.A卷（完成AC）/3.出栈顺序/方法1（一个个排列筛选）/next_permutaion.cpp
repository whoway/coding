#include<stack>
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=100000+5;

char test[maxn];
int num[maxn*2];//序列，1表示入栈，0表示出栈 
int tag=0;//多少个字符

void solution(char test[], int num[], int tag)
{
	stack<char> res;
	int temp=0;
	for(int i=1; i<=tag*2 ;i++)
	{
		if(num[i])
		{
			res.push(test[temp++]);
		}
		else
		{

			printf("%c",res.top());
			res.pop();
		}
	}
	
	printf("\n");
}


int demo()
{
	int input=0;
	int output=0;
	int k=1;
	while((input!=tag)&&(output!=tag))
	{
		if(k>2*tag)
		{
			return 0;
		}
		
		if(num[k]==1)
		{
			input++;
		}
		else
		{
			output++;
		}
		
		if(output>input)
		{
			return 0;
		}
		
		k++;
	}
	
	return 1;
}

int main()
{
	gets(test);
	for(int i=0; test[i]!='\0'; i++)
	{
		tag++;
	}

	for(int i=1; i<=2*tag ; i+=2)
	{
		num[i]=1;
	}
	
	solution(test, num, tag);
	while(next_permutation(num+1,num+2*tag+1))
	{
		if(demo())
		{
			solution(test, num, tag);
		}
		
	}
	//这种全排列的还不够好，还可以辅助卡特兰数进行break
	//	方法2：栈+DFS，然后在上面剪枝 
	//	printf("函数结束"); 
	
	return 0;
 } 
