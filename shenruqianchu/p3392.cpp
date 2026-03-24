#include <iostream>
#include <algorithm>
using namespace std;
#define maxn 55
int n,m;
char a[maxn][maxn];
int count(int row,char t){
    int tmpans = 0;
    for(int i = 1;i <= m;i++){
        if(a[row][i] != t)tmpans++;
    }
    return tmpans;
}
int main(){
    cin>>n>>m;
    for(int i = 1;i<= n;i++){
        for(int j = 1;j <= m;j++){
            cin>>a[i][j];
        }
    }
    int ans = 10000;
    for(int w = 1;w <= n - 2;w++){
        for(int b = w + 1;b <= n - 1;b++){
            int anss = 0;
            for(int i = 1; i <= w; i++) {
                anss += count(i, 'W');
            }
            
            // 蓝色区域：w+1到b行
            for(int i = w+1; i <= b; i++) {
                anss += count(i, 'B');
            }
            
            // 红色区域：b+1到n行
            for(int i = b+1; i <= n; i++) {
                anss += count(i, 'R');
            }
            ans = min(ans,anss);
        }
    }
    cout<<ans;
}