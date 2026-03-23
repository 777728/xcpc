#include <iostream>
#include <algorithm>
using namespace std; // 命名空间
#define maxn 1010 // 宏定义
#define int long long // 防溢出

signed main(){ //   主函数
    int n;
    cin>>n;
    for(int i = n;i >= 2;i--){
        cout<<i<<",";
    }
    cout<<1;
}