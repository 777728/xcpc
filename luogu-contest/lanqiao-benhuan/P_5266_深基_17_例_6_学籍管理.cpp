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
struct student{
    string name;
    int score;
    bool dead = 1;
}stu[100005];
void solve(){
    int sn = 0;
    int n;
    cin>>n;
    map<string,int>cnt;
    for(int i = 0;i < n;i++){
        int op;
        cin>>op;
        if(op == 1){
            cin>>stu[++sn].name>>stu[sn].score;
            cnt[stu[sn].name] = stu[sn].score;
            cout<<"OK"<<endl;
        }
        else if(op == 2){
            string s;
            cin>>s;
            if(cnt.count(s))cout<<cnt[s]<<endl;
            else cout<<"Not found"<<endl;
        }
        else if(op == 3){
            string s;
            cin>>s;
            if(cnt.count(s)){
                cout<<"Deleted successfully"<<endl;
                cnt.erase(s);
            }
            else cout<<"Not found"<<endl;
        }
        else{
            int ans = 0;
            cout<<cnt.size()<<endl;
        }
    }
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solve();
    return 0;
}