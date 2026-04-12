#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
void solve(){
    int n,m = 1000;
    cin>>n;
    vector<int> a(n + 1);
    vector<vector<int>> pre(n + 1,vector<int>(m + 1));
    for(int i = 1;i <= n;i++){
        cin>>a[i];
        pre[i] = pre[i - 1];
        if(i > 1){
            pre[i][a[i - 1]] = i - 1;
        }
    }
    vector<vector<int>> f(n + 1,vector<int>(n + 1));
    for(int i = 1;i <= n;i++){
        f[i][i] = 1;
        for(int j = i + 1;j <= n;j++){
            f[i][j] = 2;
        }
    }
    for(int len = 3;len <= n;len++){
        for(int l = 1;l + len - 1 <= n;l++){
            int r = l + len - 1;
            for(int x = l + 1;x < r;x++){
                int s = (a[l] + a[r] - a[x]);
                if(s < 1 || s > m || pre[r][s] < x) continue;
                f[l][r] = max(f[l][r],f[x][pre[r][s]] + 2);
            }
        }
    }
    int ans = 0;
    for(int l = 1;l <= n;l++){
        for(int r = 1;r <= n;r++){
            ans = max(ans,f[l][r]);
        }
    }
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int T;
    cin>>T;
    while(T--)
        solve();
    return 0;
}