#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 1005;
int h[maxn][maxn], l[maxn][maxn], r[maxn][maxn];
char s[maxn][maxn];

int main(){
    ios::sync_with_stdio(0); cin.tie(0); // 1. IO 优化
    int n, m, ans = 0;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> s[i][j];

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s[i][j] == 'F'){
                h[i][j] = h[i-1][j] + 1; // 全局数组 h[0][j]=0，无需特判 i=1
                l[i][j] = r[i][j] = j;
                if(j > 1 && s[i][j-1] == 'F') l[i][j] = l[i][j-1];
            } else {
                h[i][j] = 0;
            }
        }
        for(int j = m - 1; j >= 1; j--){ // 右边界反向扫描
            if(s[i][j] == 'F' && s[i][j+1] == 'F')
                r[i][j] = r[i][j+1];
        }
        for(int j = 1; j <= m; j++){
            if(i > 1 && s[i-1][j] == 'F'){ // 2. 修正：判断上一行是否为 'F'
                l[i][j] = max(l[i][j], l[i-1][j]);
                r[i][j] = min(r[i][j], r[i-1][j]);
            }
            if(s[i][j] == 'F')
                ans = max(ans, h[i][j] * (r[i][j] - l[i][j] + 1));
        }
    }
    cout << ans * 3 << endl;
    return 0;
}