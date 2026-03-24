#include<iostream>
using namespace std;
#define maxn 220
#define int long long
int a[maxn],b[maxn];
int n,na,nb;
int sa = 0,sb = 0;
int win[5][5];
signed main(){
    win[0][0] = -1,win[0][1] = 0,win[0][2] = 1,win[0][3] = 1,win[0][4] = 0;
    win[1][0] = 1,win[1][1] = -1,win[1][2] = 0,win[1][3] = 1,win[1][4] = 0;
    win[2][0] = 0,win[2][1] = 1,win[2][2] = -1,win[2][3] = 0,win[2][4] = 1;
    win[3][0] = 0,win[3][1] = 0,win[3][2] = 1,win[3][3] = -1,win[3][4] = 1;
    win[4][0] = 1,win[4][1] = 1,win[4][2] = 0,win[4][3] = 0,win[4][4] = -1;
    cin>>n>>na>>nb;
    for(int i = 0;i < na;++i)cin>>a[i];
    for(int i = 0;i < nb;++i)cin>>b[i];
    for(int i = 0;i < n;++i){
        int tmpa = a[i % na],tmpb = b[i % nb];
        if(win[tmpa][tmpb] == -1)continue;
        else{
            sa += win[tmpa][tmpb];
            sb = sb + 1 - win[tmpa][tmpb];
        }
    }
    cout<<sa<<" "<<sb;
}