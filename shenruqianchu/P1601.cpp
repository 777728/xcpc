#include<iostream>
#include<string>
#include<cmath>
using namespace std;
const int maxn = 505;
int a[maxn],b[maxn],c[maxn];
int main(){
    string n, m;
    cin >> n >> m;
    int len1 = n.size();
    int len2 = m.size();
    int len = max(len1,len2);
    for(int i = len1 - 1,j = 0;i >= 0;--i,++j){
        a[j] = n[i] - '0';
    }   
    for(int i = len2 - 1,j = 0;i >= 0;--i,++j){
        b[j] = m[i] - '0';
    }  
    for(int i = 0;i < len;++i){
        c[i] += a[i]+b[i];
        c[i + 1] = c[i] / 10;
        c[i] = c[i] % 10;
    }
    if(c[len]){
        len++;
    }
    for(int i = len-1;i >=0;--i){
        cout<<c[i];
    }
}
