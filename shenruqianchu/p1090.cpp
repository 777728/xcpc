#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int a[10010] ;
int b[10010];
signed main(){
    int n;
    cin>>n;
    memset(a,127,sizeof(a));
    memset(b,127,sizeof(b));
    for(int i = 0;i < n;i++){
        cin>>a[i];
    }
    sort(a  ,a + n );
    int ans = 0;
    int d = 0;
    int e = 0;
     int n2 = 0;   
    for(int i = 1;i < n;i++){
        int w = 0;
        w += a[d] < b[e] ? a[d++]:b[e++];
        w += a[d] < b[e] ? a[d++]:b[e++];
        b[n2++] = w;
        ans+= w;
    }
    cout<<ans;
}