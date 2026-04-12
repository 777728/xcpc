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

#define maxn 2000 * 75 + 5

int trie[maxn][26];
int word[maxn];
char str[80];
int n,tot = 0,ans = 0;
void insert(char *str){ 
    int u = 0;
    int len = strlen(str);
    int res = 0;
    for(int i = 0; i < len; i++){
        int a = str[i] - 'a';
        if(trie[u][a] == 0){
            trie[u][a] = ++tot;
        }
        u = trie[u][a];
        res += word[u];
    }
    word[u]++;
    if(res + 1 > ans)
        ans = res + 1;
}
void solve(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> str;
        insert(str);
    }
    cout << ans << endl;
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solve();
    return 0;
}