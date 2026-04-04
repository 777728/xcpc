#include<iostream>
#define maxn 500010
using namespace std;
int n,m;
int a[maxn],b[maxn],c[maxn];
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

int main(){
    cin>>n>>m;
    for(int i = 1;i <= n;i++){
        cin>>a[i];
        b[i] = a[i] - a[i - 1];
        add(i,b[i]);
    }
    while(m--){
        int op,x,y;
        cin>>op;
        if(op == 1){
            int x,y,k;
            cin>>x>>y>>k;
            add(x,k);
            add(y + 1,-k);
        }
        else{
            int x;
            cin>>x;
            cout<<sum(x)<<'\n';
        }
    }
}