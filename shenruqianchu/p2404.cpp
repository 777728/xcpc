#include<iostream>
using namespace std;
int n;
int a[100] = {1};
void print(int t){
    for(int i = 1;i < t-1;++i){
        cout<<a[i]<<"+";
    }
    cout<<a[t-1]<<endl;
}
void dfs(int s,int t){
    if(s == 0)print(t);
    if(s<0)return;
    for(int i = a[t-1];i <= s;++i){
        if(i == n)break;
        a[t] = i;
        dfs(s-i,t+1);
    }
}
int main(){
    cin>>n;
    dfs(n,1);
}