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
#define ll long long
void solve(){
    int n;
    cin>>n;
    vector<ll>a(n);
    char tmp;
    int ans = 0;
    //int ans2 = 0;
    for(int i = 0;i < n;i++) {cin>>a[i];}
    for(int i = 0;i < n;i++){
        cin>>tmp;
        if(tmp == '<'){
            if(a[i] >= 0) {ans++;a[i] = -1;}
        }
        else if(tmp == '>'){
            if(a[i] <= 0) {ans++;a[i] = 1;}
        } 
        else{
            if(i == 0) continue;
            if(a[i - 1] < 0){
                if(a[i] >= 0){
                    ans++;
                    a[i] = -1;
                }
                
            }
            else if(a[i - 1] > 0){
                if(a[i] <= 0){
                    ans++;
                    a[i] = 1;
                } 
            }  
        }
    }
    cout<<ans<<endl;

}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}