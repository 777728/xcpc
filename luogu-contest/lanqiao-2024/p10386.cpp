#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
#define maxn 1010
const int mod = 1000000007;
int ans = 0;
int a[6][6];
int white;

void dfs(int x){
    if(x > 25){
        if(white != 13) return;
        
        // 检查所有行和列是否有5连
        for(int i = 1; i <= 5; i++){
            int cnt1 = 1, cnt2 = 1;
            for(int j = 2; j <= 5; j++){
                if(a[i][j] == a[i][j-1]) cnt1++;
                else cnt1 = 1;
                if(cnt1 == 5) return;  // 有5连，不是平局
                
                if(a[j][i] == a[j-1][i]) cnt2++;
                else cnt2 = 1;
                if(cnt2 == 5) return;  // 有5连，不是平局
            }
        }
        
        // 检查主对角线（左上到右下）
        for(int i = 1; i <= 5; i++){
            int cnt = 1;
            for(int j = i+1, k = 2; j <= 5; j++, k++){
                if(a[j][k] == a[j-1][k-1]) cnt++;
                else cnt = 1;
                if(cnt == 5) return;
            }
        }
        for(int i = 2; i <= 5; i++){
            int cnt = 1;
            for(int j = i+1, k = 2; j <= 5; j++, k++){
                if(a[k][j] == a[k-1][j-1]) cnt++;
                else cnt = 1;
                if(cnt == 5) return;
            }
        }
        
        // 检查副对角线（右上到左下）
        for(int i = 1; i <= 5; i++){
            int cnt = 1;
            for(int j = i+1, k = 4; j <= 5; j++, k--){
                if(a[j][k] == a[j-1][k+1]) cnt++;
                else cnt = 1;
                if(cnt == 5) return;
            }
        }
        for(int i = 4; i >= 1; i--){
            int cnt = 1;
            for(int j = i-1, k = 5; j >= 1; j--, k--){
                if(a[k][j] == a[k-1][j+1]) cnt++;
                else cnt = 1;
                if(cnt == 5) return;
            }
        }
        
        ans++;
        return;
    }
    
    int h = (x - 1) / 5 + 1;
    int l = (x - 1) % 5 + 1;
    
    a[h][l] = 1;
    white++;
    dfs(x + 1);
    white--;
    a[h][l] = 0;
    dfs(x + 1);
}

int main(){
    white = 0;
    dfs(1);
    cout << ans;
    return 0;
}