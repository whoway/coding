#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int maxn=15000;
const int num=100000;
char str[maxn][12];
int solution[num]={0};
int n,m;

int Next[11]={0};//nextÊý×é

void getNext(char s[], int len) 
{
	int j=-1;
	Next[0]=-1;
	for(int i=1; i<len ;i++)
	{
		while(j!=-1&&s[i]!=s[j+1])
		{
			j=Next[j];
		}
		
		if(s[i]==s[j+1])
		{
			j++;
		}
		Next[i]=j;
	}
}


int KMP(char text[], char pattern[])
{
	int n_n=strlen(text),m_m=strlen(pattern);
	getNext(pattern,m_m);
	int j=-1;
	
	for(int i=0;i<n_n;i++)
	{
		while(j!=-1&&text[i]!=pattern[j+1])
		{
			j=Next[j];
		}
		
		if(text[i]==pattern[j+1])
		{
			j++;
		}
		
		if(j==m_m-1)
		{
			return 1;
		}
	}
	
	return 0;
}


int main()
{
	
	scanf("%d%d",&n,&m);
	getchar();//×¢Òâ 
	for(int i=0; i<n ; ++i)
	{
		gets(str[i]);
	}
	
	char temp[12];
	int output=0;
	
	for(int i=0; i<m ; ++i)
	{
		
		int num_out=0;
		
		gets(temp);
		
		for(int j=0; j<n ;++j)
		{
			
			char text[12];
			for(int i=0;i<12;i++)
			{
				text[i]=str[j][i];
			}
			
			output=KMP(text, temp);
//			output=cmp(temp , strlen(temp), j);
			if(output)
			{
				num_out++;
			}
		}
		
		
		solution[i]=num_out;
		
	}
	
	
	for(int i=0; i<m ; ++i)
	{
		printf("%d\n",solution[i]);
	}

	
	return 0;
 } 
