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
    int n,m;
    cin>>n>>m;
    vector<int>g[n + 10];
    for(int i = 1;i <= m;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
    }
    for(int i = 1;i <= n;i++){
        sort(g[i].begin(),g[i].end());
        for(int j = 0;j < g[i].size();j++){
            cout<<g[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    solve();
    return 0;
}