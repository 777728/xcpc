#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
signed main(){
    int n,m;
    cin>>n>>m;
    int sq = 0;
    int sqq = 0;
    int l = min(n,m);
        for(int a = 1;a <= l;a++){
            sq += (n- a + 1)*(m- a + 1);
            }
    sqq = (n + 1)*n*(m+1)*m/4 - sq;
    cout<<sq<<" "<<sqq;
}