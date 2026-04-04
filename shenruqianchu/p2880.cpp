#include<iostream>
#include<algorithm>
#define maxn 50010
using namespace std;
int n,q,h[maxn],log_2[maxn],rmax[maxn][18],rmin[maxn][18];
void init(){
    for(int i = 1;i <= n;i++){
        rmax[i][0] = rmin[i][0] = h[i];
    }
    for(int j = 1;(1 << j) <= n;j++){
        for(int i = 1;i <= n - (1 << j) + 1;i++){
            rmax[i][j] = max (rmax[i][j - 1] , rmax[i + (1 << j - 1)][j - 1]);
            rmin[i][j] = min(rmin[i][j - 1] , rmin[i + (1 << j - 1)][j - 1]);
        }
    }
}
int qmax(int a,int b){
    int x = log_2[b - a + 1];
    return max(rmax[a][x],rmax[b - (1 << x) + 1][x]);
}
int qmin(int a,int b){
    int x = log_2[b - a + 1];
    return min(rmin[a][x],rmin[b - (1 << x) + 1][x]);
}
int main(){
    cin>>n>>q;
    for(int i = 1;i <= n;i++){
        cin>>h[i];
    }
    for(int i = 2;i <= n;i++){
        log_2[i] = log_2[i >> 1] + 1;
    }
    init();
    while(q--){
        int a,b;
        cin>>a>>b;
        cout<<qmax(a,b) - qmin(a,b)<<endl;
    }
}