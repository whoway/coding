#include<stdio.h>
#include<string.h> 

const int maxn=1000000000+5;
char str[maxn];

int solution[1000+1];

void solo(int n)
{
	int one=str[1]-'0'; 
	int two=str[2]-'0'; 
	int three=str[3]-'0'; 

	while(strlen(str)<n+1)
	{
		int temp=one+two+three;
//		printf("temp=%d\n",temp);
		sprintf(str+strlen(str),"%d",temp);
//		printf("%s\n",str);
		
		int len=strlen(str);
		one=str[len-3]-'0';
		two=str[len-2]-'0';
		three=str[len-1]-'0';
	} 
	
	return;
}

int main()
{
	
	int T;
	scanf("%d",&T);
	int a,b,c,num;
	for(int i=0;i<T;i++)
	{
		scanf("%d%d%d%d",&a,&b,&c,&num);
		memset(str,0,sizeof(str));//非常易出错的地方！！！！ 
		str[0]='0'+9;//不存 
		str[1]='0'+a;
		str[2]='0'+b;
		str[3]='0'+c;
		if(num<=3)//注意1 
		{	
			solution[i]=str[num]-'0';

		}
		else
		{
			solo(num);//solo到num，再查询 
			solution[i]=str[num]-'0';
		}	
		
	}
	
	for(int i=0;i<T;i++)
	{
		printf("%d\n",solution[i]);
	}

	
	return 0;
}
