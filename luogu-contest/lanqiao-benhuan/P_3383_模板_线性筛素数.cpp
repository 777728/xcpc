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
#define maxn 10000010
unsigned int qq;
#define int long long
int n,q;
int cnt = 0;
void solve(){
    cin>>n;
    vector<bool>a(n + 10,0);
    vector<int>b(maxn,0);
    a[1] = a[0] = 1;
    for(int i = 2;i * i <= n;i++){
        if(a[i] == 0)
            for(int j = i * 2;j <= n;j += i){
                a[j] = 1;
            }
    }
    for(int i = 1;i <= n;i++){
        if(a[i] == 0){
            b[++cnt] = i;
        }
    }
    cin>>qq;
    while(qq--){
       cin>>q;
       cout<<b[q]<<'\n'; 
    }
}
signed main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solve();
    return 0;
}