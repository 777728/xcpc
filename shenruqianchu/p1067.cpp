#include<iostream>
#include<string>
using namespace std;
int a[110],vis[110];
int main(){
    int n;
    cin>>n;
    string s;
    for(int i = n ;i >= 0;i--){
        string tmp;
        cin>>tmp;
        if(tmp == "0" && s.empty() && i == 0){cout<<0;return 0;}
        if(tmp == "0") continue;
        if(i == 0){
            if(tmp[0] == '-') s += tmp;
            else if(!s.empty()) s += "+" + tmp;
            else s += tmp;
        }//次数0
        else {
            // 处理指数为1的情况
            string x_part = (i == 1) ? "x" : ("x^" + to_string(i));
            
            if(tmp == "-1"){
                if(s.empty()) s = "-" + x_part;
                else s = s + "-" + x_part;
            }
            else if(tmp == "1"){
                if(s.empty()) s = x_part;
                else s = s + "+" + x_part;
            } 
            else if(tmp[0] == '-'){
                if(s.empty()) s = tmp + x_part;
                else s = s + tmp + x_part;
            }
            else{
                if(s.empty()) s = tmp + x_part;
                else s = s + "+" + tmp + x_part;
            }
        }
    }
    if(s.empty()) cout<<0;
    else cout<<s;
}