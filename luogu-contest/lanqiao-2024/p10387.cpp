#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define maxn 1000010
#define int long long 
int n,s;
//int p[maxn],c[maxn];
//vector<int>p,c;
struct node{
    int p;
    int c;
}y[maxn];
bool cmp(node a,node b)
{
    return a.c > b.c;
}
int b[maxn];
int sum = 0;
int ans0 = 0;
int ans = 0;
signed main(){
    cin>>n>>s;
    int maxc = 0;
    for(int i = 0;i < n;i++){
        cin>>y[i].p>>y[i].c;
        sum += y[i].p;
        maxc = max(maxc,y[i].c);
    }
    sort(y,y + n,cmp);
    b[1] = y[0].p;
    for(int i = 2;i <= n;i++){
        b[i] = b[i - 1] + y[i-1].p;
    }
    for(int j = 1;j <= maxc;j++){
        bool biao = 0;
        for(int i = 0;i < n;i++){
            if(y[i].c <= 0){
            biao = i;
            break;
            }
            y[i].c--;
        }
        if(b[biao] - b[0]>=s){ans += s;}
        else {ans += b[biao] - b[0];}
    }
    
    cout<<ans;
}