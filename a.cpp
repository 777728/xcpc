#include <iostream>
#include <string>
using namespace std;

bool is_haoo2(string ss){
    int n = ss.size();
    if(ss.size() <= 1)return 1;
    else{
        for(int i = 0;i < ss.size() - 1;i++){
            if(ss[i+1] != ss[i] + 1&&ss[i + 1] != ss[i]){
                return 0;
            }
        }
        return 1;
    }
}

bool is_hao(string ss){
    int n = ss.size();
    if(ss.size() == 1)return 1;
    else{
        bool found = true;
        if(is_haoo2(ss))return 1;
        for(int i = 1;i < n;i++){
            string tmps1 = ss.substr(0,i);
            string tmps2 = ss.substr(i);
            if(is_haoo2(tmps1)&&is_haoo2(tmps2))return 1;
            }
        }
            return 0;
    }
int main(){
    string s;
    cin>>s;
    int n = s.size();
    int ans = 0;
    for(int i = 0;i < n;i++){
        for(int j = i;j < n;j++){
            string tmps = s.substr(i,j-i+1);//长度为j-i+1，起始0，长度为j-i+1
            if(is_hao(tmps))ans++;
        }
    }
    cout<<ans;
}