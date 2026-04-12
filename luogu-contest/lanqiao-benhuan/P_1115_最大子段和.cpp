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
#include<climits>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int>a(n);
    vector<long long>f(n);
    int tempans = INT_MIN;
    for(int i = 0;i < n;i++){
        cin>>a[i];
        tempans = max(tempans,a[i]);
    }
    long long ans = 0 ;
    f[0] = max(0,a[0]);
    for(int i = 1;i < n;i++){
        if(a[i] + f[i - 1] < 0) f[i] = 0;
        else{
            f[i] = f[i - 1] + a[i];
        }
    }
    bool found = 0;
    for(int i = 0;i < n;i++){
        if(f[i] > 0) found = 1;
        ans = max(ans,f[i]);
    }
    if(found)cout<<ans;
    else cout<<tempans;
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solve();
    return 0;
}