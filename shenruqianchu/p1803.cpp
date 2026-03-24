#include <iostream>
#include <algorithm>
using namespace std;

struct contest{
    int l;
    int r;
}con[1000009];

bool cmp(contest x,contest y){
    return x.r < y.r;
}

signed main(){
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++){
        cin>>con[i].l>>con[i].r;
    }
    sort(con + 1 ,con + n + 1 ,cmp);
    
    int ans = 0;
    int finish = 0;
    for(int i = 1;i <= n;i++){
        if(con[i].l<finish){
            continue;
        }
        else{
            ans++;
            finish = con[i].r;
        }
    }
    cout<<ans;
}