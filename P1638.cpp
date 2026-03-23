#include <iostream>
#include <algorithm>
using namespace std;
#define maxn 2000010
int a[maxn];
int main(){
    int n,m,ans = maxn;
    int cnt[2020] = {0};
    int num = 0;
    int l = 1,r = 1;
    int ansl = 1,ansr = 1;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    cnt[a[1]] = 1;
    num = 1;

    while(r <= n&&l <= r) {
        if(num < m){
                r++;
                cnt[a[r]]++;
                if(cnt[a[r]] == 1) num++;
            }
        else if(num==m) {
            if(ans > r - l) {
                ans = r - l;
                ansl = l;
                ansr = r;
            } 
            cnt[a[l]]--;
            if(cnt[a[l]] == 0) num--;
            l++;
        }
    }
    cout<<ansl<<" "<<ansr<<endl;
    return 0;
}