#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

struct man{
    int num;
    int time;
}water[1009];

bool cmp(man x,man y){
    return x.time < y.time;
}

signed main(){
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++){
        water[i].num = i;
        cin>>water[i].time;
    }
    sort(water + 1 ,water + n + 1 ,cmp);
    
    double ans = 0.0;
    
    for(int i = 1;i <= n;i++){
        cout<<water[i].num<<" ";
        ans += i * water[n - i].time;
    }
    cout<<endl;
    ans =  ans / n;
    cout<<fixed<<setprecision(2)<<ans;
}