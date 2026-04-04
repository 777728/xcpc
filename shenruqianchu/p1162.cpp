#include<iostream>
using namespace std;
int a[32][32],b[32][32];
int dx[5] = {0,-1,1,0,0};
int dy[5]= {0,0,0,-1,1};
int n,i,j;
void dfs(int p ,int q){
    int i;
    if(p < 0||p > n + 1||q < 0||q > n + 1||a[p][q]!=0)
        return ;
        a[p][q] = 2;
    for(int i = 1;i <= 4;++i){
        dfs(p + dx[i] , q + dy[i]);
    }
}
int main(){
    cin>>n;
    for(int i = 1;i <= n;++i){
        for(int j = 1;j <=n ; ++j){
            cin>>a[i][j];
        }
    }
    dfs(0,0);
    for(i = 1;i <= n;++i){
        for(j = 1;j <=n ; ++j){
            cout<<2 - a[i][j]<<" ";
        }
        cout<<endl;
    }
}