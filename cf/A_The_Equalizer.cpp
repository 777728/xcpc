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
    int n,k;
    cin>>n>>k;
    int sum = 0;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum += a[i];
    }
    if(sum % 2 == 1 || k * n % 2 == 0) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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