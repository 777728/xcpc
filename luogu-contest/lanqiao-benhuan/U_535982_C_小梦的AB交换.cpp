#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
using namespace std;
#define ll long long
void solve(){
    ll n;
    cin>>n;
    string s;
    cin>>s;
    string x,y;
    for(ll i = 0;i < n * 2;i++){
        if(i % 2 == 0){
            x += "A";
        }
        else{
            x += "B";
        }
    }
    //cout<<x<<" "<<y<<endl;
    ll ans1 = 0,ans2 = 0;
    for(int i = 0;i < n * 2;i++){
        if(s[i] != x[i]) ans1++;
        else ans2++;
    }
    cout<<min(ans1,ans2) / 2<<endl;
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}