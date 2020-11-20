#include<stack>
#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=100000+5;

char test[maxn];
int num[maxn*2];//序列，1表示入栈，0表示出栈 
int tag=0;//多少个字符
int input;
int output; 

int pre=0;//当前复赋值的点 
	
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

//input余下的可以入栈的数
//output下的可以出栈的数
//tag是字母的数目 
void DFS(int input, int output)
{
	if((tag-input)>(tag-output)) //出 
	{
		pre++;
		num[pre]=0;
		output--;

		DFS(input, output);
	}
	
	if(input>0)//入 
	{
		pre++;
		num[pre]=1;
		input--;

		DFS(input, output);
	}
	
	if((num[pre]==0)&&(output==0))
	{
		solution(test, num, tag);
//		cout<<"OKKKKK"<<endl;
		pre--;
		output++;
		return;
	}
	


	if((num[pre]==0)&&(output!=0))
	{
		pre--;
		++output;
		return;
	}
	else if(num[pre]==1)
	{
		pre--;
		++input;
		return;
	}
	

}


int main()
{
	gets(test);
	for(int i=0; test[i]!='\0'; i++)
	{
		tag++;
	}
	
	input=tag;
	output=tag; 
	
	DFS(input, output);
	
	printf("函数结束"); 
	
	return 0;
 } 
