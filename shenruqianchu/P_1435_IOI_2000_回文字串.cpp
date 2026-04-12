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
#define maxn 1010
string s;
int f[maxn][maxn],n;

void solve(){
    cin>>s;
    n = s.size();
    for(int i = 0;i < n;i++)
        f[i][i] = 0;
    for(int i = 1;i < n - 1;i++){
        if(s[i] == s[i - 1])
            f[i - 1][i] = 0;
        else f[i - 1][i] = 1;
    }
    for(int l = 2;l < n;l++){
        for(int i = 0;i + l < n;i++){
            int j = i + l;
            f[i][j] = min(f[i + 1][j] + 1,f[i][j - 1] + 1);
            if(s[i] == s[j])
                f[i][j] = min(f[i][j],f[i + 1][j - 1]);
        }
    }
    cout<<f[0][n - 1]<<endl;

}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solve();
    return 0;
}