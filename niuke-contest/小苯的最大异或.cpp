#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
#include<vector>
using namespace std;
#define ll long long
        


void solve(){
    int t;
    cin>>t;
    while(t--){
        ll ans = 0;
       ll x,y;
       cin>>x>>y;
       vector<ll> a,b;
       if(x == 0) {
           cout<<y<<endl;
           continue;
       }
       else if(y == 0) {
           cout<<x<<endl;
           continue;
       }

       while(1){
           a.push_back(x);
          if(x==0)break;
          x >>= 1;
       } 
       while(1){
           b.push_back(y);
          if(y==0)break;
          y >>= 1;
       } 
       for(int i = 0;i < a.size();++i){
        for(int j = 0;j < b.size();++j){
            ans = max(ans,a[i]^b[j]);
        }
       }
       cout<<ans<<endl;
    }
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solve();
    return 0;
}