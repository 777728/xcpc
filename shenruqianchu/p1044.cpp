#include<iostream>
using namespace std;
#define int long long
#define maxn 22
int h[20] = {0};

signed main(){
    int n;
    cin>>n;
    h[0]= 1;
    h[1]= 1;
    for(int i = 2;i <= n;++i){
        for(int j = 0;j < i;++j){
            h[i] += h[j] * h[i - j - 1];
        }
    }
    cout<<h[n];
}