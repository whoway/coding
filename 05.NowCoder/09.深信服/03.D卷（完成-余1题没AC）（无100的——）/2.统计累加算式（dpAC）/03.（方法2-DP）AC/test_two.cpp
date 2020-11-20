#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int dp[n+1];

    //初始化为1,表示n拆分为n个1,这一种拆分方法
    for(int i=0;i<=n;i++)
    {
        dp[i]=1;
    }

    int k=2;
    while(k<=n)
    {
        //第一次循环表示，通过将两个1，合并为2，得到的新的方法。
        //因为只有大于2的数才能够使用该拆分方法，所以j初始为2
        //以后拆分方法为4，8，16
        for(int j = k;j<=n;j++)
        {
            //原有的方法个数，加上新的拆分方法个数
            //最精妙
            dp[j]+=dp[j-k];
        }

        k*=2;
    }
    cout<<dp[n]<<endl;
}
