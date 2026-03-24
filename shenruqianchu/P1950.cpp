#include <iostream>
#include <algorithm>
using namespace std; // 命名空间
#define maxn 1010 // 宏定义
#define int long long // 防溢出
char ch[maxn][maxn]; // 网格
int n,m,top; // 变量
int h[maxn],l[maxn],r[maxn],st[maxn]; // 数组
int ans = 0; // 答案
signed main(){ // 主函数
    cin>>n>>m; // 输入行列
    for(int i = 1;i <= n;i++){ // 遍历行
       for(int j = 1;j <= m;j++){
           cin>>ch[i][j]; // 输入字符
       }
    }
    for(int i = 1;i <= n;i++){ // 逐行处理

        for(int j = 1;j <= m;j++){
            h[j] = ch[i][j] == '*' ? 0:h[j] + 1; // 更新高度
        }

        top = 0; // 重置栈

        for(int j = 1;j <= m;j++){ // 求右边界

            while(top > 0 && h[j] < h[st[top]]) {//
                r[st[top]] = j; // 第j列是第st[top]列的右界
                top--; // 弹出
            }

            top++; // 顶 +1
            st[top] = j; // 存索引
        }

        while(top > 0){ // 清算栈
            r[st[top]] = m + 1; // 右界置末
            top--; // 弹出
        }

    top = 0; // 重置栈

    for(int j = m;j >= 1;j--){ // 求左边界

        while(top > 0&&h[j] <= h[st[top]]){//直到栈顶元素高度小于当前高度
            l[st[top]] = j; // 记录左界
            top--; // 弹出
        }
        top++; // 顶 +1
        st[top] = j; // 存索引
    }
    while(top > 0){ // 清算栈
        l[st[top]] = 0; // 左界置首
        top--; // 弹出
    }
    for(int j = 1;j <= m;j++){
        ans += (j - l[j])*(r[j] - j)*h[j]; // 累加贡献
    }
    }
    cout<<ans<<endl; // 输出答案
}