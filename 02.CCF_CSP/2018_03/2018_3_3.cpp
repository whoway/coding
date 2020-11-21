#include<iostream>
#include<cstdio>
#include<vector>
#include<string>

using namespace std;
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	vector<string> aa;
	vector<string> bb;
	vector<string> cc;
	string str;
	for(int i=0;i<n;i++)
	{
		cin>>str;
		aa.push_back(str);
		cin>>str;
		bb.push_back(str);
	}
	vector<string>::iterator num1=aa.begin();
	vector<string>::iterator num2=bb.begin();
	
	for(int i=0;i<m;i++)
	{
		cin>>str;
		cc.push_back(str);
	}
	vector<string>::iterator num3=cc.begin();
	
	string test;
	vector<int> num;
	
	for(int i=0;i<n;i++)
	{
		
		if(*(num1+i).find("<str>"))
		{
			num.push_back(1);
		}
		else if(*(num1+i).find("<int>"))
		{
			num.push_back(2);
		}
		else if(*(num1+i).find("<path>"))
		num.push_back(3); 
	}
	vector<int>::iterator it=num.begin() ;
	
	
	
	
	
	
	for(int i=0;i<n;i++)
	{
		cout<<*(num1+i)<<endl;
	}
	
	
	
	
	return 0;
	
 } 


  
