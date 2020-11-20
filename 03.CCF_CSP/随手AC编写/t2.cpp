#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<cmath>
using namespace std;

struct node
{
	string str;
	int a;
	node(string id,int b): str(id),a(b) {}
};

int main()
{
	int p,r,u,q;
	scanf("%d",&p);
	vector<node> vi;
	string str,R;
	for(int i=0;i<p;i++)
	{
		cin>>str;
		string kk=":";
		if(str.find(kk)!=string::npos)
		{
			int num1,num2;
			string str1,str2;
			for(int i=0;i<str.size() ;i++)
			{
				if(str[i]==':')
				{
					num1=i;
				}
			}
			num2=str.size() ;
			str1=str.substr(0,num1);//¶ÔµÄ 
			str2=str.substr(num1+1,(num2-num1));
			
			int k=0;
			int c[str2.size()];
			
			for(int i=0;i<str2.size();i++)
			{
				c[i]=str[i]-'0';
				k=c[i]*pow(10,str2.size()-i-1)+k;
			}
			
			vi.push_back(node(str1,k)); 
		}
		else
		{
			vi.push_back(node(str,0)); 
		}
	}
	
	for(int i=0;i<p;i++)
	{
		cout<<vi[i].str<<endl;
		cout<<vi[i].a<<endl;
	}
	
	return 0;
}
