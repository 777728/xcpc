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
void solve(){
    unsigned int n;
    long long k;
    cin>>n>>k;
    vector<long long>a(n);//0
    for(int i = 0;i < n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end(),greater<long long>());
    long long qie = 0;
    long long l = 1;
    //bool found = 1;
    while(l++){
        for(int i = 0;i < n;i++){
            if(qie <= k){
                if(a[i] % l == 0){
                    qie += a[i] / l - 1;
                }
                else qie += a[i] / l;
            }
            else {
                break;
            }
        }
        if(qie <= k){
            cout<<l;
            break;
        }
        qie = 0;
    }
    return;
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solve();
    return 0;
}