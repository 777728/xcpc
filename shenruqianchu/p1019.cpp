#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string a[25];
int n, maxx, pd[25], g[25][25];

void dfs(string s, int k) {
    maxx = max(maxx, (int)s.size());
    pd[k]++;  // 使用当前单词
    
    for(int i = 1; i <= n; ++i) {
        if(g[k][i] && pd[i] < 2) {  // 只能使用次数<2的单词
            dfs(s + a[i].substr(g[k][i]), i);
        }
    }
    
    pd[k]--;  // 回溯：恢复状态
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    char s; cin >> s;
    
    // 预处理重叠长度
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            int len_i = a[i].size(), len_j = a[j].size();
            int max_overlap = min(len_i, len_j) - 1;  // 不能完全包含
            
            for(int k = 1; k <= max_overlap; k++) {
                // 修正：substr的第二个参数是长度
                if(a[i].substr(len_i - k, k) == a[j].substr(0, k)) {
                    g[i][j] = k;
                    break;  // 找到最小重叠就退出
                }
            }
        }
    }
    
    // 从每个以指定字母开头的单词开始搜索
    for(int i = 1; i <= n; i++) {
        if(a[i][0] == s) {
            dfs(a[i], i);
        }
    }
    
    cout << maxx;
    return 0;
}