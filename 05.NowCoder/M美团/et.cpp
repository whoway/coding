#include<bits/stdc++.h>
using namespace std;

//从1-6表示100-1 
int tag[7];


int main()
{
	
	int n;
	while(~scanf("%d",&n))
	{
		long long sum=0;//0种
		
		//5重循环来暴力
		for( tag[1]=0 ; tag[1]<=(n/100) ; ++tag[1] ) 
		{
			int now1=tag[1]*100;
			if(now1==n)
			{
				++sum;
				break;
			}
			else if(now1>n)
			{
				break;
			}
			
			int loop2=n-tag[1]*100;
			for( tag[2]=0; tag[2]<=(loop2/50) ; ++tag[2])
			{
				
				int now2=now1+tag[2]*50;
				if(now2==n)
				{
					++sum;
					break;
				}
				else if(now2>n)
				{
					break;
				}
				int loop3=loop2-tag[2]*50;
				for( tag[3]=0; tag[3]<=(loop3/20) ; ++tag[3])
				{
					
					int now3=now2+tag[3]*20;
					if(now3==n)
					{
						++sum;
						break;
					}
					else if(now3>n)
					{
						break;
					}
					int loop4=loop3-tag[3]*20;
					for( tag[4]=0; tag[2]<=(loop4/10) ; ++tag[4])
					{
						int now4=now3+tag[4]*10;
						if(now4==n)
						{
							++sum;
							break;
						}
						else if(now4>n)
						{
							break;
						}
						int loop5=loop4-tag[4]*10;
						for( tag[5]=0; tag[5]<=(loop5/5) ; ++tag[5])
						{
							int now5=now4+tag[4]*5;
							if(now5==n)
							{
								++sum;
								break;
							}
							else if(now5>n)
							{
								break;
							}
							int loop6=loop5-tag[5]*5;
							for( tag[6]=0; tag[6]<=loop6 ; ++tag[6])
							{
								int now6=now5+tag[6];
								if(now6==n)
								{
									++sum;
									break;
								}
								else if(now6>n)
								{
									break;
								}
	
							}
						}
					}
				}
			}
		}
		
		
		printf("%lld\n",sum);
	}
	return 0;
}
