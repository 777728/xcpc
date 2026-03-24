
#include <bits/stdc++.h>
#define maxn 2500
using namespace std;
int n,m;
char a[maxn][maxn],b[maxn][maxn];
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>m;
    memset(a,'.',sizeof(a));
    memset(b,'.',sizeof(b));
    int tmpa1 = (n + 3)/4;
    int tmpa2 = (n + 1)/2;
    for(int i = 1;i <= n;i++){
        a[i][tmpa1] = '#';
    }
    int j = tmpa1 + 1;
    for(int i = tmpa2 - 1;i >= 1;i--){
            a[i][j] = '#';
            j++;
    }
    j = tmpa1 + 1;
    for(int i = tmpa2 + 1;i <= n;i++){
            a[i][j] = '#';
            j++;
    }
    int tmpb = (m + 1)/2;
    j = 1;
    for(int i = 1;i < tmpb;i++){
        
        b[i][j] = '#';
        j++;
    }
    j = tmpb + 1;
    for(int i = tmpb - 1;i >= 1;i--){
            b[i][j] = '#';
        j++;
    }
    for(int i = tmpb;i <= m;i++){
        b[i][tmpb] = '#';
    }
    if(n < m){
        for(int i = n + 1;i <= m;i++){
            for(int j = 1;j <= n;j++){
                a[i][j] = ' ';
            }
        }
    }
    else if(m < n){
        for(int i = m + 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                b[i][j] = ' ';
            }
        }
    }
    for(int i  = 1;i <= max(n,m);i++){
        for(int j = 1;j <= n;j++){
            cout<<a[i][j];           
        }
        cout<<" ";
        for(int j = 1;j <= m;j++){
            cout<<b[i][j];
        }
        if(i < max(n,m)) cout<<"\n";
    }
}