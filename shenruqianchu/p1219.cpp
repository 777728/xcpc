#include <iostream>
using namespace std;
int a[100];
int ans = 0;
int n;
int vis[4][100];
void dfs(int num){
    if(num > n){
        ans++;
        if(ans <= 3){
            for(int i = 1;i <= n;++i){
                cout<<a[i]<<(i==n?"":" "); // 修复：行末无空格
            }
            cout<<endl;
        }
        return;
    }
    
    for(int i = 1;i <= n;++i ){
        if(!vis[1][i]&&!vis[2][num+i]&&!vis[3][num - i + n]){
            a[num] = i; 
            vis[1][i] = 1;
            vis[2][num+i] = 1;
            vis[3][num - i + n] = 1; // 修复：与判断条件保持一致
            dfs(num + 1);
            vis[1][i] = 0;
            vis[2][num+i] = 0;
            vis[3][num - i + n] = 0; // 修复：与判断条件保持一致
        }
    }
}

int main(){
    cin>>n;
    dfs(1);
    cout<<ans<<endl; // 修复：补充换行
    return 0;
}