#include <iostream>
#include <list>
#include <vector>
#include <iterator> // 用于 std::next
using namespace std;

// 全局变量，防止栈溢出，且方便访问
const int MAXN = 500005;
list<int> s;
vector<list<int>::iterator> pos(MAXN); // pos[i] 存储数字 i 的迭代器
vector<bool> deleted(MAXN, false);     // 标记数字是否被删除

void solve() {
    int n, m;
    cin >> n >> m;

    // 1. 初始化链表: 1 -> 2 -> ... -> n
    for (int i = 1; i <= n; ++i) {
        s.push_back(i);
    }

    // 2. 记录初始迭代器位置
    auto it = s.begin();
    for (int i = 1; i <= n; ++i) {
        pos[i] = it;
        ++it;
    }

    // 3. 处理指令
    for (int i = 0; i < m; ++i) {
        int op;
        cin >> op;
        if (op == 1) {
            // 1 x y: 将 x 插入到 y 的左侧
            int x, y;
            cin >> x >> y;
            if (x == y) continue;
            if (deleted[x] || deleted[y]) continue;

            // 如果 x 当前在链表中，先移除它（相当于从原位置剪下来）
            // 注意：题目隐含意思是移动节点，如果 x 不在链表中(已删除)，上面continue了
            // 如果 x 在链表中，erase 会使 pos[x] 失效，但我们要重新 insert 并更新 pos[x]
            s.erase(pos[x]); 
            
            // 在 y 的左侧插入 x (即在 pos[y] 之前插入)
            auto it_y = pos[y];
            auto new_it = s.insert(it_y, x);
            pos[x] = new_it; // 更新 x 的新位置

        } else if (op == 2) {
            // 2 x y: 将 x 插入到 y 的右侧
            int x, y;
            cin >> x >> y;
            if (x == y) continue;
            if (deleted[x] || deleted[y]) continue;

            // 同样，先从原位置移除 x
            s.erase(pos[x]);

            // 在 y 的右侧插入 x (即在 pos[y] 的下一个位置之前插入)
            auto it_y = pos[y];
            auto next_it = next(it_y); // 获取 y 后面的迭代器
            auto new_it = s.insert(next_it, x);
            pos[x] = new_it; // 更新 x 的新位置

        } else {
            // 3 x: 删除 x
            int x;
            cin >> x;
            if (deleted[x]) continue; // 如果已经删过，忽略

            s.erase(pos[x]);      // 从链表中移除
            deleted[x] = true;    // 标记为已删除
        }
    }

    // 4. 输出结果
    if (s.empty()) {
        cout << "Empty!" << endl;
    } else {
        for (auto it = s.begin(); it != s.end(); ++it) {
            if (it != s.begin()) cout << " ";
            cout << *it;
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}