#include<iostream>
#include<string>
using namespace std;
const int maxn = 1e6+5;
struct node{
    int name;
    string job;
}a[maxn];

int main(){
    int n, m,x,y;
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        cin>>a[i].name>>a[i].job;
    }
    int now = 0;
    for(int i = 0;i < m;i++){
        cin>>x>>y;
        if(x == 0&&a[now].name == 0)
            now = (now + n - y)%n;
        if(x == 1&&a[now].name == 0)
            now = (now +  y)%n;
        if(x == 0&&a[now].name == 1)
           now = (now +  y)%n;
        if(x == 1&&a[now].name == 1)
           now = (now + n - y)%n;
    }
    cout<<a[now].job;
}
// (x == 1&&a[now].name == 1)