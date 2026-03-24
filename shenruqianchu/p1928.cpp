#include<iostream>
#include<string>
using namespace std;
#define int long long
#define maxn 1010
int vis[maxn];

string expand(){
    char c;int d;
    string x;
    string ans;
    while(cin>>c){
        if(c == '['){
            cin>>d;
            x = expand();
            while(d--){
                ans += x;
            }
        }
        else if(c == ']'){
            return ans;
        }
        else{
            ans += c;
        }
    }
    return ans;
} 

signed main(){
    cout<<expand();
}