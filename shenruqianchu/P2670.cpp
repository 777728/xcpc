#include <iostream>
using namespace std;
#define maxn 110
int dx[9] = {-1,0,1,-1,0,1,-1,0,1};
int dy[9] = {1,1,1,0,0,0,-1,-1,-1};
char ch[maxn][maxn];
int n,m;
int main(){
    cin>>n>>m;
    for(int i = 1;i <= n;++i){
        for(int j = 1;j <= m;j++){
            cin>>ch[i][j];
        }
    }

    for(int i = 1;i <= n;++i){
        for(int j = 1;j <= m;j++){
            if(ch[i][j] == '*') cout<<'*';
            else{
                int ans = 0;
                for(int k = 0;k < 9;k++){
                    if(ch[i + dx[k]][j + dy[k]] == '*'){
                        ans++;
                    }
                }
                cout<<ans;
            }
        }
        cout<<endl;
    }
}