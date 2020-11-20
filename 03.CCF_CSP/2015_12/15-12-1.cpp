#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main()
{
	string str;
	cin>>str;
	int sum=0;
	
	for(string::iterator it=str.begin();it!=str.end();it++)
	{
		sum=sum+(*it-'0');
	}
	printf("%d",sum);
	
	return 0;
}

//虽然题目中说那个是输入一个数字，但是我用cin输入到string类型中，也OK
//是100分 
