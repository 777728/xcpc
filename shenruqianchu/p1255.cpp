#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string f[5005];

string add(string a,string b){
    int tmp1[10000] = {0}, tmp2[10000] = {0}, tmp3[10000] = {0};
    string ans;
    int len = max(a.length(),b.length());
    for(int i = a.length() - 1,j = 1;i >= 0;i--,j++){
      tmp1[j] = a[i] - '0';   
    }
    for(int i = b.length() - 1,j = 1;i >= 0;i--,j++){
      tmp2[j] = b[i] - '0'; 
    }
    for(int i = 1;i <= len;i++){
        tmp3[i] += tmp1[i] + tmp2[i];
        tmp3[i+1] = tmp3[i] / 10;
        tmp3[i] =  tmp3[i] % 10;
    }
    if(tmp3[len+1]) len++;
    for(int i = len;i > 0;i--){
        ans += tmp3[i] + '0';
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    f[1] = "1";
    f[2] = "2";
    if(n == 1){ cout<<1;return 0;}
    if(n == 2) {cout<<2;return 0;}
    for(int i = 3;i <= n;++i){
        f[i] = add(f[i - 1],f[i - 2]);
    }
    cout<<f[n];
}