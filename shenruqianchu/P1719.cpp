#include<iostream>
using namespace std; // 命名空间
#define maxn 100010 // 宏定义
int n,m;
int a[maxn],s[maxn];
int main(){ // 主函数
    cin>>n;
    for(int i = 1;i <= n;i++){
        cin>>a[i];
        s[i] = s[i-1] + a[i]; // 计算前缀和
    }
    cin>>m;
    for(int i = 1;i <= m;i++){
        int a,b;
        cin>>a>>b;
        cout<<s[b] - s[a-1]<<endl; // 输出区间和
    }
}