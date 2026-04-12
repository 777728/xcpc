#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
using namespace std;
int fa[200005];
int find(int x){
    if(fa[x] == x) return x;
    //find(fa[x]);
    fa[x] = find(fa[x]);
    return fa[x];
}
void merge(int x,int y){
    int fax = find(x),fay = find(y);
    if(fax == fay) return;
    fa[fax] = fay; 
}
void query(int x,int y){
    int fax = find(x),fay = find(y);
    if(fax == fay) cout<<"Y"<<endl;
    else cout<<"N"<<endl;
}
void solve(){
    int n,m;
    cin>>n>>m;
    for(int i = 1;i <= n;i++){
        fa[i] = i;
    }
    for(int i = 1;i <= m;i++){
        int z,x,y;
        cin>>z>>x>>y;
        if(z == 1){
            merge(x,y);
        }
        else query(x,y);
    }
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solve();
    return 0;
}