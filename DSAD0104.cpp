#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
#define maxn 200010
int ans = 0;
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++){
        for(int j = 1; j<= n-i+1;j++){
            cout<<i<<" * "<<j<<" = "<<i*j<<"   ";
        }   
        cout<<endl;
    }
    return 0;
}
