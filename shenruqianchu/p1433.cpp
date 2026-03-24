#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
using namespace std;
double a[20][20];
double x[20], y[20];
double f[20][34000];
int n;
double distance(int v, int w) {
    return sqrt((x[v] - x[w]) * (x[v] - x[w]) + (y[v] - y[w]) * (y[v] - y[w]));
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
    }
    x[0] = y[0] = 0;
    
    // 计算所有点之间的距离
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            a[i][j] = distance(i, j);
        }
    }
    
    // 初始化DP数组为很大的数
    int total = 1 << n;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < total; j++) {
            f[i][j] = 1e9; // 初始化为一个很大的数
        }
    }
    
    // 初始化：从起点(0,0)到每个奶酪的距离
    for (int i = 1; i <= n; ++i) {
        f[i][1 << (i - 1)] = a[0][i];
    }
    
    // DP过程
    for (int k = 1; k < total; k++) {
        for (int i = 1; i <= n; i++) {
            // 检查状态k中是否包含i
            if (!(k & (1 << (i - 1)))) continue;
            
            for (int j = 1; j <= n; j++) {
                if (i == j) continue;
                // 检查状态k中是否包含j
                if (!(k & (1 << (j - 1)))) continue;
                
                // 状态转移：从j走到i
                // 注意：f[j][k - (1 << (i - 1))] 表示在访问了除i以外的点后最后在j的最短距离
                f[i][k] = min(f[i][k], f[j][k - (1 << (i - 1))] + a[i][j]);
            }
        }
    }
    
    // 找出最终答案
    double ans = 1e9;
    for (int i = 1; i <= n; i++) {
        ans = min(ans, f[i][total - 1]);
    }
    
    // 输出结果，保留2位小数
    cout << fixed << setprecision(2) << ans << endl;
    
    return 0;
}