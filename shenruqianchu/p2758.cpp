#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
//const int maxn = 50;
const int inf = 2e9;
#define mod 998244353
#define maxn 2010

int n,f[maxn][maxn];
string a,b;

int main(){
    ios::sync_with_stdio(false);
    cin >> a >> b;
    int n = a.size(), m = b.size();
    for(int i = 1;i <= n;i++) f[i][0] = i;
    for(int j = 1;j <= m;j++) f[0][j] = j;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            f[i][j] = min(min(f[i - 1][j] + 1,f[i][j - 1] + 1),f[i - 1][j - 1] + (a[i - 1] != b[j - 1]));
        }
    }
    cout << f[n][m] << endl;
}