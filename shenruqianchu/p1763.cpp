#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

int dep = 1, st[11], ans[11], flag;
int gcd(int x, int y) {
    if (y == 0) return x;
    return gcd(y, x % y);
}

void dfs(int a, int b, int x) {
    if (x > dep) return;

    // 如果已经只剩一个单位分数
    if (a == 1 && b > st[x - 1]) {
        st[x] = b;
        if (!flag || st[x] < ans[x]) {
            for (int i = 1; i <= dep; i++) {
                ans[i] = st[i];
            }
            flag = 1;
        }
        return;
    }

    // 当前分母的下界（比上一个分母大，且至少 ceil(b/a)）
    int l = max((b + a - 1) / a, st[x - 1] + 1);
    // 上界（剩下的分数个数 * 当前最大可能分母）
    int r = (dep - x + 1) * b / a;
    if (flag && r >= ans[dep]) {
        r = ans[dep] - 1;
    }

    for (int i = l; i <= r; i++) {
        st[x] = i;
        int na = a * i - b;
        int nb = b * i;
        int g = gcd(na, nb);
        dfs(na / g, nb / g, x + 1);
    }
}

int main() {
    int a, b;
    cin >> a >> b;
    int g = gcd(a, b);
    a /= g;
    b /= g;
    st[0] = 1;  // 第 0 个分母设为 1，保证第一个分母从 2 开始

    for (dep = 1; dep <= 10; dep++) {
        dfs(a, b, 1);
        if (flag) {
            for (int i = 1; i <= dep; i++) {
                cout << ans[i] <<" ";
            }
            break;
        }
    }
    return 0;
}