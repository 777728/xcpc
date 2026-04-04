#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;
#define maxn 66
int n,sum,d;
int len[maxn],a[maxn],pre[maxn];
void dfs(int u,int k,int p){//当前还有u没有拼，还有k根没有拼，当前最短长度为p
    if(u == 0) {dfs(d,k -1,a[n]);return ;}
    else if(k == 0){cout<<d;exit(0);}
    p = (p < u) ? p : u;
    while(p && len[p] == 0)--p;
    while(p){
        if(len[p]){
            --len[p];
            dfs(u - p,k,p);
            ++len[p];
            if(u == p|| u == d) return;
            p = pre[p];
        }
        else p = pre[p];
    }
}
int main(){
    cin>>n;
    for(int i = 1,x;i <= n;++i){
        cin>>x;
        sum += x;
        ++len[a[i] = x];
    }
    sort(a + 1,a + 1 + n);
    for(int i = 1;i <= n;i++){
        if(a[i] != a[i - 1]) pre[a[i]] = a[i - 1];
    }
    for(d = a[n];(d << 1) <= sum;++d){
        if((sum % d) == 0)
            dfs(d,sum / d,a[n]);
    }
    cout<<sum;
}