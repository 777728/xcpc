#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
#include<vector>
using namespace std;
#define ll long long
 vector<ll>g[200010];
vector<ll>a(200010);
ll ans = 0;
 void dfs(int u, int p, ll len) {
    if (p != -1 && a[u] == a[p]) {
        len++;
    } else {
        len = 1;
    }
    ans += (len - 1);

    for (int v : g[u]) {
        if (v == p) continue;
        dfs(v, u, len);
    }
}
void addedge(int u ,int v){
    g[u].push_back(v);
    g[v].push_back(u);
}

void solve(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
          for (int i = 1; i <= n; i++) {
        g[i].clear();
    }

        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<n;i++) {
            int u, v;
            cin>>u>>v;
            addedge(u,v);
        }
        ans= 0;
        dfs(1, -1, 0);
        cout<<ans<<endl;
    }
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solve();
    return 0;
}