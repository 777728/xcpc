#include <iostream>
using namespace std;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int x,y;
        cin >> x >> y;
        int n = x + y;
        int d = y - x;
        if((x == 0 && n % 2 == 0) || x > n / 2){
            cout<<"No"<<endl;
            continue;
        }
        cout<<"Yes"<<endl;
        int mm = 2 * x + (d % 2);

        for(int i = 2;i <= mm;i++){
            cout<<i - 1<<" "<<i<<" "<<endl;
        }
        for(int i = mm + 1;i <= n;i++){
            cout<<mm<<" "<<i<<" "<<endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}