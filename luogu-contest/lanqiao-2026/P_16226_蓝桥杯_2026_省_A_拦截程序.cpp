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
#define int long long
void solve(){
    int l,v,t;
    cin>>l>>v>>t;
    int pa = v * t,pb = l - v * t;
    int cha = abs(pb - pa);
    int yiban = cha / 2;
    int p = max(yiban,cha - yiban);
    cout<<p<<endl;
}
signed main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int c;
    cin>>c;
    while(c--)
    solve();
    return 0;
}