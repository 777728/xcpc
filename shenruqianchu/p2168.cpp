//#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
#define int long long
struct node{
    int w,h;
};
priority_queue<node> q;
bool operator < ( node a,node b){
    if(a.w != b.w) return a.w > b.w;
    return a.h > b.h;
}
signed main(){
    int n,k;
    cin>>n>>k;
    int ans = 0,wi;
    for(int i=1;i <= n;i++){
        cin>>wi;
        q.push(node{wi,1});
    }
    if((n - 1) % ( k - 1) != 0){
        for(int i=1;i <= ( k - 1) - (n - 1) % ( k - 1);i++){
            q.push(node{0,1});
        }
    }
    while(q.size() > 1){
        node tmp;
        int sum = 0,maxh = 0;
        for(int i = 1;i <= k;i++){
            tmp = q.top();
            sum += tmp.w;
            maxh = max(maxh,tmp.h);
            q.pop();
        }
        ans += sum;
        q.push(node{sum,maxh + 1});
    }
    cout << ans << endl << q.top().h - 1 << endl;    
}