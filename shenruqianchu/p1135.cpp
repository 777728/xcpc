#include <iostream>
#include <cstring>
using namespace std;
int INF =0x3f3f3f3f;
int ans[205] = {INF},a,b,dis[205] = {0},n;
void dfs(int s,int t){
    ans[s] = t;
    if(s + dis[s] <= n && t + 1 < ans[s+dis[s]])
        dfs(s + dis[s],t + 1);
    if(s - dis[s] > 0 && t + 1 < ans[s-dis[s]])
        dfs(s - dis[s],t + 1);
    return;
}
int main(){
    memset (ans,INF,sizeof(ans));
    cin>>n>>a>>b;
    for(int i = 1;i <= n;++i){
        cin>>dis[i]; 
    }
    dfs(a,0);
    if(ans[b] != INF)
        cout<<ans[b];
    else cout<<-1;
    return 0;
}