#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
#define maxn 200010
typedef long long ll;
const int mod = 1000000007;

ll c[maxn],d[maxn];
vector<int>cc[maxn],dd[maxn];
bool vis1[maxn],vis2[maxn];

bool cmp1(int &x,int &y){
    return c[x] < c[y];
}
bool cmp2(int &x,int &y){
    return d[x] < d[y];
}

int main(){
    int n,m;
    cin>>n>>m;
    for(int i = 1;i <= n;i++){
        cin>>c[i];
    }
    for(int i = 1;i <= m;i++){
        cin>>d[i];
    }
    for(int i = 1;i < n;i++){
        int u,v;
        cin>>u>>v;
        cc[u].push_back(v);
        cc[v].push_back(u);
    }
    for(int i = 1;i < m;i++){
        int u,v;
        cin>>u>>v;
        dd[u].push_back(v);
        dd[v].push_back(u);
    }
    for(int i = 1;i < n;i++){
        sort(cc[i].begin(),cc[i].end(),cmp1);
    }
    for(int i = 1;i < m;i++){
        sort(dd[i].begin(),dd[i].end(),cmp2);
    }
    struct node{
        int id1,id2,dep;
    };
    queue<node>q;
    int ans = 0;
    if(c[1] != d[1]){
        cout<<ans;
        return 0;
    }//两个的出发点必须相同
    q.push({1,1,1});
    while(!q.empty()){
        auto tmp = q.front();
        q.pop();
        vis1[tmp.id1] = 1;
        vis2[tmp.id2] = 1;
        ans = max(ans,tmp.dep);
        int i = 0,j = 0;
        while(i < cc[tmp.id1].size()&&j < dd[tmp.id2].size()){
            int t1 = cc[tmp.id1][i],t2 = dd[tmp.id2][j];
            if(c[t1] < d[t2]) i++;
            else if(c[t1] > d[t2]) j++;
            else{
                if(vis1[t1] == 0 && vis2[t2] == 0)
                    q.push({t1,t2,tmp.dep + 1});
                i++,j++; 
            }
        }
    }
    cout<<ans;
    
}