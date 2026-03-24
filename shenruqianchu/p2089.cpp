#include<iostream>
using namespace std;
#define rep(i,a,b) for(int i = a; i <= b; i++)

int main() {
    int n, ans = 0;
    cin >> n;
    
    // 第一次循环统计总数
    rep(a,1,3) rep(b,1,3) rep(c,1,3) rep(d,1,3) rep(e,1,3)
    rep(f,1,3) rep(g,1,3) rep(h,1,3) rep(i,1,3) rep(j,1,3)
        if (a + b + c + d + e + f + g + h + i + j == n)
            ans++;
    
    cout << ans << endl;
    
    // 第二次循环输出所有方案
    if (ans > 0) {
        rep(a,1,3) rep(b,1,3) rep(c,1,3) rep(d,1,3) rep(e,1,3)
        rep(f,1,3) rep(g,1,3) rep(h,1,3) rep(i,1,3) rep(j,1,3)
            if (a + b + c + d + e + f + g + h + i + j == n)
                cout << a << " " << b << " " << c << " " << d << " " << e << " "
                     << f << " " << g << " " << h << " " << i << " " << j << endl;
    }
    
    return 0;
}