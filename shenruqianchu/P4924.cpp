#include<iostream>
using namespace std;
int n,m;
int mtx[505][505],tmp[505][505],cnt;
int main(){
    cin>>n>>m;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            ++cnt;
            mtx[i][j] = cnt;
        }
    }
    for(int i = 1;i <= m;++i){
        int x,y,r,z;
        cin>>x>>y>>r>>z;
        if(z == 0){
            for(int i = x - r;i <= x + r;i++){
                for(int j = y - r;j <= y + r;j++){
                    tmp[x-y+j][x+y-i] = mtx[i][j];
                }
            }
        }
        else{
            for(int i = x - r;i <= x + r;i++){
                for(int j = y - r;j <= y + r;j++){
                    tmp[x+y-j][y-x+i] = mtx[i][j];
                }
            }
        }
        for(int i = x - r;i <= x + r;i++){
                for(int j = y - r;j <= y + r;j++){
                    mtx[i][j] = tmp[i][j];
                }
            }
    }
    for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                cout<<mtx[i][j]<<" ";
            }
            cout<<endl;
        }
}