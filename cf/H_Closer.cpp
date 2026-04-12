#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> w(n + 1);
    for (int i = 1; i <= n; ++i) cin >> w[i];
    
    int total_nodes = 2 * n;
    vector<int> a(total_nodes + 1);
    vector<int> pos(n + 1, -1); // 记录每个数字第一次出现的位置
    
    for (int i = 1; i <= total_nodes; ++i) {
        cin >> a[i];
        if (pos[a[i]] == -1) {
            pos[a[i]] = i;
        } else {
            // 第二次出现，可以立即计算距离（如果有深度信息）
            // 但我们需要先建树和算深度
        }
    }
    
    vector<vector<int>> adj(total_nodes + 1);
    for (int i = 0; i < total_nodes - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    // 计算深度 (BFS/DFS)
    vector<int> depth(total_nodes + 1, -1);
    depth[1] = 0;
    vector<int> q = {1};
    for (int i = 0; i < (int)q.size(); ++i) {
        int u = q[i];
        for (int v : adj[u]) {
            if (depth[v] == -1) {
                depth[v] = depth[u] + 1;
                q.push_back(v);
            }
        }
    }
    
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        int u = pos[i];
        // 找第二个位置：遍历 a 数组太慢，应该在输入时存下来
        // 修改输入部分逻辑
    }
}