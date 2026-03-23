//L
#include <iostream>
#include <queue>
#include <set>
using namespace std;
int n;
long long t;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>n;
    while(n--){
        cin>>t;
        if(t == 1||t == 4||t == 7||t == 9||t == 10||t == 12||t == 13||t >= 15) cout<<"YES\n";
        else cout<<"NO\n";
    }
}