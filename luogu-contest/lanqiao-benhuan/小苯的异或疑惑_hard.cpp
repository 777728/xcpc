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
void solve(){
    int n;
    cin>>n;
    long long a,b = 0;
    
    for(int i = 0;i < n;i++){
        cin>>a;
        b ^= a;
    }
    if((n - 1) % 2 == 0) cout<<0;
    else cout<<b;
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solve();
    return 0;
}