#include<iostream>
#define maxn 500010
#define ll long long
using namespace std;
ll a[maxn],w[maxn * 4];
void pushup(int u){
    w[u] = w[u * 2] + w[u * 2 + 1];
}
void build(int u,int l,int r){
    if(l == r){
        w[u] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(u * 2, l, mid);
    build(u * 2 + 1, mid + 1, r);
    pushup(u);
}
bool inrange(int L ,int R,int l,int r){
    if(L <= l && r <= R)  return true;
    return false;
}
bool outrange(int L,int R,int l,int r){
    if(R < l || r < L) return true;
    return false;
}   
ll query(int u,int l,int r,int L,int R){
    if(inrange(L,R,l,r)) return w[u];
    if(outrange(L,R,l,r)) return 0;
    int mid = (l + r) / 2;
    return query(u * 2, l, mid, L, R) + query(u * 2 + 1, mid + 1, r, L, R);
}
ll lzy[maxn * 4];
void maketag(int u ,int len,ll x){
    lzy[u] += x;
    w[u] += len * x;
}
void pushdown(int u,int l,int r){
    if(lzy[u] == 0) return;
    int mid = (l + r) / 2;
    maketag(u * 2, mid - l + 1, lzy[u]);
    maketag(u * 2 + 1, r - mid, lzy[u]);
    lzy[u] = 0;
}
ll query2(int u,int l,int r,int L,int R){
    if(inrange(L,R,l,r)) return w[u];
    if(outrange(L,R,l,r)) return 0;
    pushdown(u,l,r);
    int mid = (l + r) / 2;
    return query2(u * 2, l, mid, L, R) + query2(u * 2 + 1, mid + 1, r, L, R);
}
void update(int u,int l,int r,int L,int R,ll x){
    if(inrange(L,R,l,r)){
        maketag(u,r - l + 1,x);
    }
    else if(!outrange(L,R,l,r)){
        pushdown(u,l,r);
        int mid = (l + r) / 2;
        update(u * 2, l, mid, L, R, x);
        update(u * 2 + 1, mid + 1, r, L, R, x);
        pushup(u);
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i = 1;i <= n;i++){
        cin>>a[i];
    }
    build(1,1,n);
    while(m--){
        int op,x,y;
        ll k;
        cin>>op;
        if(op == 1){
            cin>>x>>y>>k;
            update(1,1,n,x,y,k);
        }
        else{
            cin>>x>>y;
            cout<<query2(1,1,n,x,y)<<'\n';
        }
    }
}