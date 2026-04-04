#include<iostream>
#include<algorithm>
#define int long long 
int ans = 0,ansl = 0,ansr = 0;
#define maxn 1010
int a[maxn][maxn];
using namespace std;
int s[maxn][maxn];
int b[maxn][maxn];
signed main(){
    int n,m,c;
    cin>>n>>m>>c;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            cin>>a[i][j];
            s[i][j] = s[i][j - 1] +s[i - 1][j] - s[i - 1][j - 1] + a[i][j];
        }
    }
    for(int i = c;i <= n;i++){
        for(int j = c;j <= m;j++){
            b[i][j] = s[i][j] - s[i - c][j] - s[i][j - c] + s[i - c][j - c];
            if(ans < b[i][j]){
                ans = b[i][j];
                ansl = i - c + 1;
                ansr = j - c + 1;
            }
        }
    }
    cout<<ansl<<" "<<ansr;
}