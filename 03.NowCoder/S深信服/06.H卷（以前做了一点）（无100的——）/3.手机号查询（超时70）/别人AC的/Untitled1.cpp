#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3+5;
typedef long long ll;
 
unordered_map<string,bool>vis;
unordered_map<string,int>cnt;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    string s;
    while(n--){
        cin>>s;
        if(vis.count(s)) continue;
        vis[s]=true;
        set<string>st;
        for(int i=0;i<11;i++){
            for(int j=i;j<11;j++){
                st.insert(s.substr(i,j-i+1));
            }
        }
        for(auto t:st) cnt[t]++;
    }
    while(m--){
        cin>>s;
        cout<<cnt[s]<<'\n';
    }
    return 0;
}
