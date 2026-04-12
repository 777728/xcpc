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
#define ll unsigned int
//#define ll unsigned long long 

int n;
void solve(){
    queue<ll>st;
    cin>>n;
    for(int i = 0;i < n;i++){
        int s;
        cin>>s;
        if(s == 1){
            ll x;
            cin>>x;
            st.push(x);
        }
        else if(s == 2){
            if(st.empty()) cout<<"ERR_CANNOT_POP"<<endl;
            else {
                st.pop();
            }
        }
        else if(s == 3){
            if(st.empty()) cout<<"ERR_CANNOT_QUERY"<<endl;
            else cout<<st.front()<<endl;
        }
        else {
            cout<<st.size()<<endl;
        }
    }   
}
signed main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    solve();
    return 0;
}