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
    vector<long long> a(n);
    for(int i = 0;i < n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    long long x = 0;
    for(int i = 0;i < n;i++){
        if(i%2 == 0) x += a[i];
        else x -= a[i];
    }
    cout<<x<<endl;
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solve();
    return 0;
}