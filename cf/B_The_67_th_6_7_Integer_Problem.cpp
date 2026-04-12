#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
void solve(){
    int t;
    cin>>t;
    while(t--){
        int a[8];
        int sum = 0;
        for(int i = 0;i < 7;i++){
            cin>>a[i];
            sum += a[i];
        }
        sort(a,a+7);
        cout<< - sum + a[6] * 2<<endl;
    }
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solve();
    
}