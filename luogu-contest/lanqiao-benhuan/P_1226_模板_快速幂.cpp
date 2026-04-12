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
int a,b,p;
int mi(int a,int ci){
    if(ci == 0) return 1 % p;
    int s = mi(a,ci / 2);
    if(ci % 2 == 0) return s * s % p;
    else return s * s % p * a % p;
}
void solve(){
    cin>>a>>b>>p;
    cout<<a<<"^"<<b<<" "<<"mod"<<" "<<p<<"="<<mi(a%p,b);
}
signed main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solve();
    return 0;
}