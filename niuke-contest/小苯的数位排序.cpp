#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
#define ll long long
vector<ll> a;

ll dig(ll x){
    ll res=0;
    while(x){
        res += x%10;
        x /= 10;
    }
    return res;
}

void solve(){
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        for(ll i=0;i<n;i++){
            ll tmp;
            cin>>tmp;
            a.push_back(tmp);
            if(i == 0){
                ll tt = dig(tmp);
                while(tt >= 10){tt = dig(tt);}
                a[i] = tt;
            }
            else if(i > 0&&a[i-1] > tmp){
                cout<<-1<<endl;
            }
            else{
                ll ttt;
                ll tt = dig(tmp);
                while(tt >= a[i-1]){ ttt = tt;tt = dig(tt);}
                a[i] = ttt;
            }
        }

    }
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solve();
    return 0;
}