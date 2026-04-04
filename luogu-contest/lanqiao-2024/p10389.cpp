#include <iostream>
#include <vector>
using namespace std;

// 计算方差函数
double calculate_variance(long long sum, long long sum_sq, int k) {
    double mean = (double)sum / k;
    return (double)sum_sq / k - (double)mean * mean;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    double t;
    cin >> n >> k >> t;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // 如果 n < k，直接输出 -1
    if (n < k) {
        cout << -1 << endl;
        return 0;
    }

    // 初始化窗口
    long long sum = 0, sum_sq = 0;
    for (int i = 0; i < k; ++i) {
        sum += a[i];
        sum_sq += (long long)a[i] * a[i];
    }

    // 检查初始窗口
    if (calculate_variance(sum, sum_sq, k) < t) {
        cout << k << endl;
        return 0;
    }

    // 滑动窗口遍历剩余部分
    for (int i = k; i < n; ++i) {
        // 更新窗口的 sum 和 sum_sq
        sum = sum - a[i - k] + a[i];
        sum_sq = sum_sq - (long long)a[i - k] * a[i - k] + (long long)a[i] * a[i];

        // 计算方差
        if (calculate_variance(sum, sum_sq, k) < t) {
            cout << i + 1 << endl; // 输出当前窗口的结束位置
            return 0;
        }
    }

    // 如果找不到满足条件的窗口
    cout << -1 << endl;
    return 0;
}