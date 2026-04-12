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
typedef long long LL;
const int N = 1e6 + 10;
LL n, s, p[N], c[N], cnt[N], Sum, now, ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> s;
// cnt[i] 记录还需要训练 i 次的那些士兵，单独训练一次的总成本
// now 记录当前还需要训练的士兵，单独训练一次的总成本
// Sum 记录如果全部单独训练的总成本

// 初始化
for (int i = 1; i <= n; i++) {
    cin >> p[i] >> c[i];
    cnt[c[i]] += p[i];  // 这个次数的累加成本
    now += p[i];        // 所剩的士兵单独训练一次的总成本
    Sum += p[i] * c[i]; // 全部单独训练的总成本
}
	for (int i = 1; i <= 1e6; i++) {
		if (now < s)  break;
		ans += s;
		Sum -= now;
		now -= cnt[i];
	}
	cout << ans + Sum;
	return 0;
}
