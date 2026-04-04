#include<iostream>
#include<cstdio>
using namespace std;
#define maxn 500010
int a[maxn];
long long ans;
int merge_sort(int a[],int l,int r){
    if(l == r)return a[l];
    int mid =( l + r)>> 1;
    merge_sort(a,l,mid),merge_sort(a,mid+1,r);
    return a[l] + a[r];
}
int main(){
    int i = 0;
    while(cin>>a[i]) {
        i++;
    }
    for(int j = 0;j <= i-1;++j){
        ans += a[j] * (1LL << (i - 1));
    }
    cout<<ans;
}