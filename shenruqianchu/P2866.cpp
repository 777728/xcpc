#include <iostream>
#include <algorithm>
using namespace std;
#define maxn 100010
#define int long long       
int s[maxn],top = 0;
signed main(){
    int n,h;
    int ans = 0;
    cin>>n;
    for(int i = 1;i <= n;i++){
        cin>>h;
        while(top>0&&h >= s[top]) top--;
        ans += top;
        s[++top] = h;
    }
    cout<<ans<<endl;
}