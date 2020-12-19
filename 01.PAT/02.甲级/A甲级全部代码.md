# 1001 A+B Format (20分)


## 一、思路和难点




## 二、代码（别人的）

```cpp
#include <iostream>
#include <stack>
using namespace std;
int main()
{
    stack <int> s;
    long int a,b,x;
    int bool_1=0;
    int j=0,k=0;
    cin>>a>>b;
    x=a+b;

   if(x==0)
   {
       cout<<x;
       return 0;
   }
    
    if(x<0)
    {
        x=x*(-1);
        bool_1=1;
    }
    while(x)
    {
        s.push(x%10);
        x/=10;
        j++;
    }
    while (!s.empty())
    {
        if(bool_1==1)
        {
              cout<<'-';
              bool_1=0;
        }
        j--;
        cout<<s.top();
        s.pop();

        if(j%3==0&&j!=0)
            cout<<',';
    }
    return 0;
}
```
