#include <iostream>
#include <cstdio>
using namespace std;
#define maxn 105
int n,m;
char biao[maxn][maxn];
int fa[10050];

int find(int x) {
    if(x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}

int cal(int i, int j) {
    return (i-1) * m + j;  // 注意这里是 m，不是 n
}

void join(int c1, int c2) {
    int f1 = find(c1), f2 = find(c2);
    if(f1 != f2) fa[f1] = f2;
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> biao[i][j];
            fa[cal(i,j)] = cal(i,j);  // 全部初始化
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(biao[i][j] != 'W') continue;
            // 检查 8 个方向，但为了避免重复合并，只检查右、下、右下、左下 4 个方向即可
            if(i+1 <= n && j-1 >= 1 && biao[i+1][j-1] == 'W') join(cal(i,j), cal(i+1,j-1)); // 左下
            if(i+1 <= n && biao[i+1][j] == 'W') join(cal(i,j), cal(i+1,j)); // 下
            if(i+1 <= n && j+1 <= m && biao[i+1][j+1] == 'W') join(cal(i,j), cal(i+1,j+1)); // 右下
            if(j+1 <= m && biao[i][j+1] == 'W') join(cal(i,j), cal(i,j+1)); // 右
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(biao[i][j] == 'W' && find(cal(i,j)) == cal(i,j)) ans++;
        }
    }
    cout << ans;
    return 0;
}