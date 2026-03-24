#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
#define maxn 200010

bool isprime(int x){
    if(x <= 1) return false;
    for(int i = 2;i * i <= x;i++){
        if(x % i == 0) return false;
    }
    return true;
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin>>t;
    if(isprime(t)){
        cout<<"true\n";
    }
    else{
        cout<<"false\n";
    }
    return 0;
}