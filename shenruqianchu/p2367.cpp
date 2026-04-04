#include<iostream>
#include<cstdio>
using namespace std;
#define maxn 5000010
int n,m,x,y,z,a[maxn],b[maxn];
int ans = 0;
int main(){
    cin>>n>>m;
    for(int i = 1;i <= n;i++){
        cin>>a[i];
        b[i] = a[i] - a[i -1];
    }
    for(int i = 1;i <= m;i++){
        cin>>x>>y>>z;
        b[x] += z;
        b[y + 1] -= z;
    }
    int min = 101;
    for(int i = 1; i<= n;i++){
        b[i] += b[i - 1];
        if(b[i] < min)min = b[i];
    }
    cout<<min;
}