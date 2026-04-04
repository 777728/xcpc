#include<iostream>
#include<cstring>
#define ll long long
#define maxn 10010
using namespace std;
int ans,a[maxn],f[maxn],n;

int main(){
    while(cin>>a[++n]);
    n--;
    for(int i = 1;i <= n;i++){
        f[i] = 1;
        for(int j = 1;j < i;j ++){
            if(a[j] >= a[i])
                f[i] = max(f[i],f[j] + 1);
        }
        ans = max(ans,f[i]);
    }
    cout<<ans<<endl;
    ans = 0;
    for(int i = 1;i <= n;i++){
        f[i] = 1;
        for(int j = 1;j < i;j ++){
            if(a[j] < a[i])
                f[i] = max(f[i],f[j] + 1);
        }
        ans = max(ans,f[i]);
    }
    cout<<ans<<endl;
}