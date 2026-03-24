#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, d, k;
    cin >> n >> d >> k;
// 无解判断
    if(d + 1 > n) {
    cout << -1 << endl;
    return 0;
    }
    if(k == 1) {
        if(n == 2 && d == 1)
        cout << "1 2" << endl;
        else
        cout << -1 << endl;
    return 0;
    }
    if(k == 2) {
        if(n == d + 1) {
            for(int i = 1; i <= d; i++)
            cout << i << " " << i + 1 << endl;  
        } else cout << -1 << endl;
    return 0;
    }
// 构造直径主干
    vector<pair<int, int>> edges;
    vector<int> deg(n + 1, 0);
        for(int i = 1; i <= d; i++) {
        edges.push_back({i, i + 1});
        deg[i]++;
        deg[i + 1]++;
        }
// BFS 填充剩余节点
    int cur = d + 2;
    queue<pair<int, int>> q; // {节点, 最大扩展深度}
    for(int i = 2; i <= d; i++) {
    int max_depth = min(i - 1, d + 1 - i);
    q.push({i, max_depth});
    }
    while(!q.empty() && cur <= n) {
    auto [u, depth] = q.front();
    q.pop();
    if(depth == 0) continue;
    int can_add = k - deg[u];
    for(int i = 0; i < can_add && cur <= n; i++) {
    edges.push_back({u, cur});
    deg[u]++;
    deg[cur]++;
    if(depth > 1)
    q.push({cur, depth - 1});
    cur++;
    }   
    }
// 检查是否所有节点都加入了
if(cur <= n) {
cout << -1 << endl;
return 0;
}
for(auto [u, v] : edges)
cout << u << " " << v << endl;
return 0;
}