#include <iostream>
#include <cmath>
#define int long long
using namespace std;
char ch;
char a[10000000];
int num = 0;
int f[2] = {11,21};

signed main(){
    while(cin>>ch){
        if(ch == 'E'){
            if(num == 0) {
            cout<<"0:0"<<endl;
            cout<<endl;
            cout<<"0:0"<<endl;
            return 0;
        }
        break;
        }
        a[num++] = ch;
    }
    
    for(int i = 0;i < 2;i ++){
        int w = 0,l = 0;
        for(int j = 0;j < num;j++){
            a[j] == 'W' ? w = w + 1 : l +=1;
            if((w >= f[i] || l >= f[i]) && abs(w - l) >=2){
                cout<<w<<":"<<l<<endl;
                w = 0,l = 0;
            }
        }
        if(w != 0 || l != 0){
            cout<<w<<":"<<l<<endl;
        }
        cout<<endl;
    } 
    
}