#include <iostream>
#include <string>
using namespace std;
#define int long long

signed main() {
    string s;
    int n;
    cin >> s >> n;
    
    int len = s.length();
    
    // 找到包含n的最小字符串长度
    int cur_len = len;
    while (cur_len < n) {
        cur_len *= 2;
    }
    
    // 反向追踪到原始字符串
    while (cur_len > len) {
        int half = cur_len / 2;
        
        if (n > half) {
            // 如果n在后半部分
            if (n == half + 1) {
                // 后半部分的第一个字符对应原始字符串的最后一个
                n = half;
            } else {
                // 其他位置：n映射到前半部分的前一个位置
                n = n - half - 1;
            }
        }
        cur_len = half;
    }
    
    // 输出结果
    cout << s[n - 1] << endl;
    
    return 0;
}