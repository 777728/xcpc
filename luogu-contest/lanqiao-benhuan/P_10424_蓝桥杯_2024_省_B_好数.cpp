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
bool check(int x){
    int cnt = 1;
    while(x != 0){
        if(x % 2 == cnt % 2){
            x /= 10;
            cnt++;
        }
        else return 0;
    }
    return 1;
}
void solve(){
    long long num;
    cin>>num;
    int ans = 0;
    for(int i = 1;i <= num;i++){
        ans += check(i);
    }
    cout<<ans;
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solve();
    return 0;
}