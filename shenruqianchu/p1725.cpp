#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN = 200005;
const int INF = 2100000000;
int n, l, r;
int a[MAXN], f[MAXN], q[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin >> n >> l >> r;
    for(int i = 0; i <= n; i++) cin >> a[i];
    
    for(int i = 1; i <= n; i++) f[i] = -INF;
    f[0] = 0;
    
    int head = 0, tail = 0;
    int ans = -INF;
    
    for(int i = 1; i <= n; i++){
        // 将合法前驱 i-l 加入单调队列
        if(i - l >= 0){
            while(head < tail && f[i - l] >= f[q[tail - 1]]) tail--;
            q[tail++] = i - l;
        }
        // 移除超出跳跃范围 i-r 的前驱
        while(head < tail && q[head] < i - r) head++;
        
        // 状态转移
        if(head < tail && f[q[head]] > -INF) 
            f[i] = f[q[head]] + a[i];
        
        // 若能从 i 跳出河岸 (存在跳跃点 > N)
        if(i + r > n) ans = max(ans, f[i]);
    }
    // 特殊情况：直接从 0 跳出
    if(l > n) ans = max(ans, f[0]);
    
    cout << ans << endl;
    return 0;
}