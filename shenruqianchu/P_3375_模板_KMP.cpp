#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
using namespace std;
#define maxn 1000005

int len1,len2;
string s1,s2;
int b[maxn];

void solve(){
    cin>>s1>>s2;
    len1=s1.size();
    len2=s2.size();
    int j=0;
    for(int i = 1;i < len2;i++){
        while(j > 0 && s2[i] != s2[j]){
            j = b[j-1];
        }
        if(s2[j] == s2[i]) j++;
        b[i] = j;
    }
    j = 0;
    for(int i = 0;i < len1;i++){
        while(j > 0 && s1[i] != s2[j]){
            j = b[j-1];
        }
        if(s1[i] == s2[j]) j++;
        if(j == len2){
            cout<<i + 1 -len2+1<<endl;
            j = b[j-1];
        }
    }
    for(int i = 0;i < len2;i++){
        cout<<b[i]<<" ";
    }
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solve();
    return 0;
}