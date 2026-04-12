#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
using namespace std;
int a[10][10];
//bool vis[10][10];
set<int>s[2][6];//行列 具体行数
bool check(){
    if(a[2][2] != 3 || a[3][1] != 3 || a[5][4] != 4 || a[5][5] != 1) return 0;
    if(a[1][2] >= a[1][3] || a[1][3] >= a[1][4] || a[1][4] >= a[1][5]) return 0;
    if(a[2][3] <= a[2][4] || a[3][2] <= a[4][2] || a[3][4] <= a[3][5]) return 0;
    return 1;
}
void dfs(int num){
    if(num > 25){
        if(check()){
            for(int i = 1;i <= 5;i++){
                for(int j = 1;j <= 5;j++){
                    cout<<a[i][j]<<" ";
                }
                cout<<endl;
            }
        } 
        return; 
    }
    int tx = (num - 1) / 5 + 1;
    int ty = (num - 1) % 5 + 1;
    for(int i = 1;i <= 5;i++){
        if(s[0][tx].count(i) || s[1][ty].count(i))continue;
        if(ty == 5 && s[0][tx].size() != 4) continue;
        if(tx == 5 && s[1][ty].size() != 4) continue;
        a[tx][ty] = i;
        s[0][tx].insert(i);
        s[1][ty].insert(i);
        dfs(num + 1);
        s[0][tx].erase(i);
        s[1][ty].erase(i);
    }
}
void solve(){
    dfs(1);
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solve();
    return 0;
}