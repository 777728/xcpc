#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define maxn 5050
#define int long long
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    double ans = 0.0;
    double a[maxn],b[maxn];
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin>>a[i];
    }
    for(int i = 1;i <= m;i++){
        cin>>b[i];
    }
    sort(a + 1,a + n + 1);
    sort(b + 1,b + m + 1);
    for(int j = 1;j <= m;j++){
        for(int i = n ;i >= 1;i--){
            if(a[i] < b[j]){
                a[i] = (a[i] + b[j]) / 2;
                b[j] = a[i];
            }
        }
    }
    for(int i = 1;i <= n;i++){
        ans += a[i];
    }
    cout<<ans<<"\n";
}