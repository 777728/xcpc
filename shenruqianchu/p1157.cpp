#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;

int main(){
    int n,r;
    cin>>n>>r;
    for(int s = (1 << n) - 1; s >= 0; s--){
        int cnt = 0;
        vector<int> selected;  // 只在需要时记录
        for(int i = n - 1; i >= 0; i--){
            if((1<<i) & s) {
                selected.push_back(n - i);  // 直接记录数字
                cnt++;
            }
        }
        if(cnt == r){
            // 已经是从小到大的顺序，因为是从高位遍历到低位
            for(int x : selected){
                cout << setw(3) << x;
            }
            cout << endl;
        }
    }
    return 0;
}