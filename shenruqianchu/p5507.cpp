#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
#define maxn 1010
const int n = 1 << 24;
int g[n],nxt[12][4],fa[n],ans[20],choice[n];
struct node{
    int state;
    double f;
    node(int s) : state(s){
        double h = 0;
        f = 0;
        for(int i = 0;i < 12;i++){
            if((s >> (1 * 2)) & 3)
                h += 4 - ((s >> (1 * 2)) & 3);
        }
        f = h + g[s];
    }
    bool operator < (const node &y)const{
        return f > y.f;
    }
};
priority_queue<node>q;
int main(){
    int button,start = 0;
    for(int i = 0;i < 12;i ++){
        cin>>button;
        start |= (button - 1) << (i * 2);
        for(int j = 0 ;j < 4;j++){
            cin>>nxt[i][j];
            nxt[i][j] -= 1;
        }
    }
    q.push(node(start));
    g[start] = 0;
    while(!q.empty()){
        int state = q.top().state;
        q.pop();
        if(state == 0) break;
        int si,snxt,nx,nextstate;
        for(int i = 0;i < 12;i++){
            si = (state >> (i * 2)) & 3;
            nx = nxt[i][si];
            snxt = (state >> (nx * 2)) & 3;
            nextstate = state ^ (si << (i * 2)) ^ (((si + 1) & 3) << (i * 2));
            nextstate = nextstate ^ (snxt << ( nx * 2 )) ^ (((snxt + 1) & 3) << (nx * 2));
            if(!g[nextstate]){
                g[nextstate] = g[state] + 1;
                fa[nextstate] = state;
                choice[nextstate] = i + 1;
                q.push(node(nextstate));
            }
        }
    }
    int cnt = 0,state = 0;
    while(state != start){
        ans[++cnt] = choice[state];
        state = fa[state];
    }
    cout<<cnt<<endl;
    for(int i = cnt;i > 0;i--){
        cout<<ans[i]<<" ";
    }
}