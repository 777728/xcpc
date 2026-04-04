#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn = 50;
#define maxs 100010
const int inf = 2e9;
#define mod 998244353
#define maxv 20010
int f[maxn][maxs],t,n,num[maxn][maxn];
string s;

int main(){
    ios::sync_with_stdio(false);
    cin >> s >> t;
    n = s.size();
    memset(f,127,sizeof(f));
    f[0][0] = -1;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= i;j ++){
            if(num[j][i - 1] > t) num[j][i] = inf;
            else num[j][i] = num[j][i - 1] * 10 + s[i - 1] - '0';
        }
    }
    for(int i = 1;i <= n;i++){
        for(int s = 0;s <= t;s++){
            for(int j = i - 1;j >= 0&&num[j + 1][i] <= t;j--){
                if(s >= num[j+ 1][i])
                    f[i][s] = min(f[i][s],f[j][s - num[j + 1][i]] + 1);
            }
        }
    }
    cout<<(f[n][t] >= maxn ? -1 : f[n][t])<<endl;
}