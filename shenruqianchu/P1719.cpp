#include<iostream>
using namespace std; 
#define maxn 1010 
int n,m;
int a[maxn][maxn],s[maxn][maxn];
int qsum(int x1,int y1,int x2,int y2){
    return s[x2][y2] + s[x1 - 1][y1 - 1] - s[x2][y1 - 1] - s[x1 - 1][y2];
}
int main(){ // 主函数
    cin>>n;
    for(int i =1;i <= n;i ++){
        for(int j = 1;j <= n;j++){
            cin>>a[i][j];
            s[i][j] = a[i][j] + s[i - 1][j] + s[i][j - 1] - s[i -1][j - 1];

        }
    }
    int ans = -10000000,sum;
    for(int i = 1;i <= n;i ++){
        for(int j = i ;j <= n;j++){
            sum = 0;
            for(int k = 1;k <= n;k++){
                sum += qsum(i,k,j,k);
                if(sum > ans) ans = sum;
                if(sum < 0) sum = 0;
            }
        }
    }
    cout<<ans;
}