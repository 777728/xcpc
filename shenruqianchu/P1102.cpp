#include <iostream>
#include <algorithm>
using namespace std;
#define maxn 200010
#define int long long
int a[maxn];
signed main(){
    int n,c,ans = 0;
    cin>>n>>c;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    int l = 0,r = 0;
    for(int i = 0;i<n;i++){
        
        while(a[l] < a[i]-c&&l<n) l++;
        while(a[r] <= a[i]-c&&r<n) r++;
        if(a[i] - c == a[l])ans += r - l;   
    }
    cout<<ans<<endl;
    return 0;
}