#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;
int main()
{
	string str;
	str="123";
	int str1;
	int c[str.size() ];
	for(int i=0;i<str.size() ;i++)
	{
		c[i]=str[i]-'0';
	}

	for(int i=0;i<str.size() ;i++)
	{
		cout<<c[i];
	}
	return 0;
}
