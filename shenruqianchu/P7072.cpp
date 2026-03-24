#include <iostream>
#include <algorithm>
using namespace std;
#define maxn 200010
int a[maxn];
int main(){
    int n,w;
    cin>>n>>w;
    int cnt[620] = {0};
    int a[maxn];
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cnt[a[i]]++;
        int sum = 0;
        for(int j = 600;j >= 0;j--){
            sum += cnt[j];
            if(sum >=max(1,i * w / 100)) {
                cout<<j<<" ";
                break;
            }
        }
    } 

    
    
}