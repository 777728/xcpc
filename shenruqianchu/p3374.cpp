#include<iostream>
#define maxn 500010
using namespace std;
int n,m;
int a[maxn],c[maxn];
int pre[maxn];
int lowbit(int x){return x & (-x);} 
void add(int x,int y){
    for(int i = x;i <= n;i += lowbit(i)) c[i] += y;
}
int sum(int x){
    int res = 0;
    for(int i = x;i > 0;i -= lowbit(i)) res += c[i];
    return res;
}
void init(){
    for(int i = 1;i <= n;i++){
        pre[i] = pre[i - 1] + a[i];
        c[i] = pre[i] - pre[i - lowbit(i)];
    }
}
int main(){
    cin>>n>>m;
    for(int i = 1;i <= n;i++){
        cin>>a[i];
    }
    init();
    while(m--){
        int op,x,y;
        cin>>op>>x>>y;
        if(op == 1)
            add(x,y); 
        else cout<<sum(y) - sum(x - 1)<<'\n';
    }
}