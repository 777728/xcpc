#include <iostream>
#include <vector>
#include <numeric>
#include <utility>
using namespace std;    // 使用标准命名空间

// 定义并查集结构体
struct DSU {
    vector<int> fa;     // fa[i] 存储节点 i 的父节点

    // 构造函数：初始化并查集，大小为 n+1
    DSU(int n) {
        fa.resize(n + 1);
        iota(fa.begin(), fa.end(), 0); // 将 fa 初始化为 0, 1, ..., n
    }

    // 查找根节点（带路径压缩）
    int get(int x) {
        while (x != fa[x]) {
            x = fa[x] = fa[fa[x]]; // 路径压缩优化
        }
        return x;
    }

    // 合并两个集合
    bool merge(int x, int y) {
        x = get(x), y = get(y);
        // 注意：原代码此处有笔误 "retuif"，逻辑应为：
        if (x == y) return false; // 如果已在同一集合，返回 false
        fa[y] = x;                // 否则合并
        return true;
    }

    // 判断两个节点是否在同一集合
    bool same(int x, int y) {
        return get(x) == get(y);
    }
};

int main() {
    // 关闭同步，加速 C++ 输入输出
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m; // 读取节点数 n 和边数 m

    DSU dsu(n); // 初始化并查集
    vector<pair<int, int>> edges0; // 用于存储权重 w=0 的边

    // 读取所有边
    for(int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        if(w == 1)
            dsu.merge(u, v);       // 若 w=1，直接合并（视为已激活/连通）
        else
            edges0.push_back({u, v}); // 若 w=0，暂存起来后续处理
    }

    int res = 0;
    // 遍历所有 w=0 的边
    for(auto [u, v]: edges0) {
        if(dsu.same(u, v))
            res++;                 // 若 u, v 已连通，加这条边会形成环，操作数 +1
        else
            dsu.merge(u, v);       // 若未连通，则合并（将该边加入生成树）
    }

    cout << res << endl; // 输出最大操作次数
    return 0;
}