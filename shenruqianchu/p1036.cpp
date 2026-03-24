#include <iostream>
using namespace std;
inline bool isprime(int x){
    if(x == 1)return false;
    for(int i = 2; i * i <= x;++i){
        if(x % i == 0) return false;
    }
    return true;
}
const int N = 25;
int a[N],ans,n,k;

void dfs(int now,int sum,int sid){
    if(now == k){
        if(isprime(sum)){
            ++ans;
        }
        return;
    }
    for(int i = sid;i <= n - k + now;++i){
        dfs(now + 1, sum + a[i], i + 1);
    }
    return;
}
int main(){
    cin>>n>>k;
    for (int i = 0; i < n; ++i){
        cin>>a[i];}
        dfs(0,0,0);
    cout<<ans<<endl;
}