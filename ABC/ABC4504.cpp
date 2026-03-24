#include<iostream>
#include<algorithm>
#include<vector>
using namespace std; // 命名空间
#define maxn 200010 // 宏定义
//#define int long long // 防溢出
vector<long long> a; // 数组
int main(){ //   主函数
    ios::sync_with_stdio(0); cin.tie(0);
    int n,k;
    cin>>n>>k;
    a.resize(n);
    for(int i = 0;i < n;i++){
        cin>>a[i]; // 输入数组
        a[i] = a[i] % k; // 取模
    }
    sort(a.begin(),a.end()); // 排序
    long long maxg = 0;
    for(int i = 0;i < n - 1;i++){
        maxg = max(maxg,a[i+1] - a[i]); // 计算最大间隔
    }
    maxg = max(maxg,a[0] + k - a[n-1]); // 考虑环形情况
    cout<<k - maxg<<endl; // 输出结果
}