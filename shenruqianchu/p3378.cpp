#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int w[maxn];
int tot = 0;
void modify(int x){
    if(x == 1 || w[x] > w[x / 2])
        return;
    swap(w[x],w[x / 2]);
    modify(x / 2);
}
void repair(int x){
    if(x * 2 > tot)return;
    int tar = x * 2;
    if(x * 2 + 1 <= tot)
    tar = w[x * 2] < w[x * 2 + 1] ? tar : x * 2 + 1;
    if(w[x] > w[tar]) {
        swap(w[x], w[tar]);
        repair(tar);   
    }
}
void push(int x){
    w[++tot]=x;
    modify(tot);
}
int top(){
    return w[1];
}
void pop(){
    swap(w[1],w[tot]);
    tot--;
    repair(1);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,x;
    cin>>n;
    while(n--){
        int op,x;
        cin>>op;
        if(op == 1){
            cin>>x;
            push(x);
        }
        else if(op == 2){
            cout<<top()<<'\n';
        }
        else pop();
    }
}