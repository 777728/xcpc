#include<algorithm>
#include<iostream>
using namespace std;

int main(){
    int a[10010],n,m;
    cin>>n>>m;
    for(int i = 1;i <= n;i++){
        cin>>a[i];
    }
    for(;m--;){
        next_permutation(a + 1,a + n + 1);
    }
    for(int i = 1;i <= n;++i){
        cout<<a[i]<<' ';
    }
    return 0;
}