#include<bits/stdc++.h>
#define i64 long long // 定义长整型别名，防止溢出
using namespace std;
const int mod = 1e6+3; // 题目给定的模数 10^6 + 3

// 快速幂函数：计算 (a^b) % mod
i64 powmod(i64 a, i64 b) {
    i64 res = 1;
    while(b) {
        if(b&1) res = res * a % mod; // 若指数二进制末位为 1，累乘底数
        b >>= 1; // 指数右移一位（除以 2）
        a = a * a % mod; // 底数平方
    }
    return res;
}

int main() {
    i64 n;
    cin>>n; // 输入节点数 n
    i64 m;
    // 计算总方案数的指数：m = n*(n-1)/2
    // 根据费马小定理，指数需对 mod-1 取模
    // 分奇偶讨论是为了先执行除法，避免 n*(n-1) 溢出 long long
    if(n&1) { // n 为奇数
        m = (n-1)/2 % (mod-1);
        m = m * (n % (mod-1)) % (mod-1);
    } else { // n 为偶数
        m = n/2 % (mod-1);
        m = m * ((n-1) % (mod-1)) % (mod-1);
    }

    int ans;
    i64 t = 1;
    // 判断 n 与 mod 的大小关系
    if(n >= 1e6+3) {
        // 若 n >= mod，则 n! 中包含因子 mod，故 n! % mod = 0
        // 此时答案 = 2^m - 0
        ans = powmod(2, m);
    } else {
        // 若 n < mod，需手动计算 n! % mod
        for(int i = 2;i<=n;i++) {
            t = t * i % mod;
        }
        // 答案 = 2^m - n!
        // + mod 是为了防止减法结果为负数
        ans = powmod(2, m) - t + mod;
        ans %= mod;
    }
    cout<<ans; // 输出最终结果
    return 0;
}