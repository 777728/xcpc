#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
using namespace std;
struct drug{
    int t;
    int m;
}yao[110];
void solve(){
    int t,m;
    cin>>t>>m;
    vector<int>f(t + 10,0);
    for(int i = 1;i <= m;i++){
        cin>>yao[i].t>>yao[i].m;
    }
    for (int i = 1; i <= m; i++) {
        // 内层循环：逆序遍历时间（容量）
        // 必须从 T  downto  yao[i].t，保证每株草药只被选一次
        for (int j = t; j >= yao[i].t; j--) {
            // 状态转移：选或不选，取最大值
            f[j] = max(f[j], f[j - yao[i].t] + yao[i].m);
        }
    }
    cout<<f[t];
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solve();
    return 0;
}