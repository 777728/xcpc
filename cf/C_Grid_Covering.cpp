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

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

void solve(){
    int n,m,a,b;
    cin>>n>>m>>a>>b;
    if(gcd(n,a) == 1 && gcd(m,b) == 1 && gcd(n,m) <= 2) cout<<"yes"<<endl;
    else cout<<"no"<<endl;


}
signed main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--)
      solve();
    return 0;
}