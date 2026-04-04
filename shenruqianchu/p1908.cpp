#include<iostream>
#include<cstdio>
using namespace std;
#define maxn 500010
int n,a[maxn],t[maxn];
long long ans;
void merge_sort(int a[],int l,int r){
    if(l == r)return;
    int mid =( l + r)>> 1;
    merge_sort(a,l,mid),merge_sort(a,mid+1,r);
    for(int i = l,j = l,k = mid + 1;i <= r;i++){
        if(j == mid + 1) t[i] = a[k++];
        else if(k == r + 1){
            t[i] = a[j++];
            ans += k - mid - 1;
        }
        else if(a[j] <= a[k]){
            t[i] = a[j++];
            ans += k - mid - 1;
        }
        else t[i] = a[k++];
    }
    for(int i = l;i <= r;i++){
        a[i] = t[i];
    }
}
int main(){
    cin>>n;
    for(int i = 1;i <= n;i++){
        cin>>a[i];
    }
    merge_sort(a,1,n);
    cout<<ans;
}