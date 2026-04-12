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
    vector<int>a(n);
    vector<long long>b(n + 1);
    b[0] = 0;
    for(int i = 0;i < n;i++){
        cin>>a[i];
        b[i + 1] = b[i] + a[i];
    }
   
    int m;
    cin>>m;
    for(int i = 0;i < m;i++){
        int l,r;
        cin>>l>>r;
        cout<<b[r] - b[l - 1]<<endl;
    }
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solve();
    return 0;
}