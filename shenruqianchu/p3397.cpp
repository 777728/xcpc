#include<iostream>
#include<cstdio>
using namespace std;
#define maxn 1010
int n,m,x1,y1,x2,y2,a[maxn][maxn];
int main(){
    cin>>n>>m;
    for(int i = 1;i <= m;i++){
        cin>>x1>>y1>>x2>>y2;
        a[x1][y1]++;
        a[x1][y2 + 1]--;
        a[x2 + 1][y1]--;
        a[x2 + 1][y2 + 1]++;
    }
    
    
    for(int i = 1; i<= n;i++){
       for(int j = 1;j <= n;j++){
        a[i][j] += a[i -1 ][j] + a[i][j - 1] - a[i - 1][j - 1];
        cout<<a[i][j]<<" ";
       }
       cout<<endl;
    }
}