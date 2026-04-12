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
    
    void solve(){
        int n,k;
        cin>>n>>k;
        vector<int> a(n);
        vector<int> b(n, -1); 
        map<int, int> cnt;
        for(int i=0;i<n;i++) {
            cin>>a[i];
            cnt[a[i]] = i;
        }
        sort(a.begin(),a.end());
        reverse(a.begin(), a.end());
        int i = 0;
        while(cnt[a[i]] > i && k >= (cnt[a[i]] - i)){
            k -= (cnt[a[i]] - i);
            b[i] = a[i];
            i++;
        }
        for(int j=0;j<n;j++){
            cout<<b[j]<<" ";
        }
    }
    
    int main(){
        ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
        solve();
        return 0;
    }