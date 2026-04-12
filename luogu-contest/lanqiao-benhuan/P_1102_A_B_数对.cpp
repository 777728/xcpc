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
    int n,c;
    cin>>n>>c;
    long long ans = 0;
    vector<int>a(n);
    for(int i = 0;i < n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    for(int i = 0;i < n;i++){
        if(a[i] + c <= a[n - 1]){
            auto x = lower_bound(a.begin(),a.end(),a[i] + c);
            auto y = upper_bound(a.begin(),a.end(),a[i] + c);
            ans += y - x;
        }
    }
    cout<<ans;
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solve();
    return 0;
}