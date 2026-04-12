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
set<int>s;
void solve(){
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++){
        int op;
        int length;
        cin>>op;
        if(op == 1){
            cin>>length;
            if(s.count(length) != 0) cout<<"Already Exist"<<endl;
            else s.insert(length);
        }
        else{
            cin>>length;
            if(s.empty()) cout<<"Empty"<<endl;
            else if(s.count(length) != 0) {
                s.erase(length);
                cout<<length<<endl;
            }
            else {
                //auto ll = lower_bound(s.begin(),s.end(),length);
                auto it = upper_bound(s.begin(),s.end(),length);
                if(it == s.begin()){
                    cout<<*it<<endl;
                    s.erase(s.begin());
                }
                else if(it == s.end()){
                    --it;
                    cout<<*it<<endl;
                    s.erase(*it);
                }
                else {
                    auto itl = --it;
                    it++;
                    int cha = (*it - length) - (length - *itl);
                    if(cha > 0) {
                        cout<<*itl<<endl;
                        s.erase(*itl);
                    }
                    else if(cha < 0){
                        cout<<*it<<endl;
                        s.erase(*it);
                    }
                    else{
                        if(*itl < *it) {
                            cout<<*itl<<endl;
                            s.erase(*itl);
                        }
                        else{
                            cout<<*it<<endl;
                            s.erase(*it);
                        }
                    }
                }
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solve();
    return 0;
}