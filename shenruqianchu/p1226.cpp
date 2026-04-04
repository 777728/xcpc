#include<iostream>
#include<cstdio>
#define int long long

using namespace std;
int b,p,k;
int power(int y,int x){
    if(x == 0)return 1 % k;
    int s = power(y,x / 2);
    if(x % 2 == 0){
        return s * s % k;
    }
    return s * s % k * y % k;

}
signed main(){
    cin>>b>>p>>k;
    cout<<b<<"^"<<p<<" "<<"mod"<<" "<<k<<"="<<power(b % k,p);
    return 0;
}