#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

struct StringInfo {
    string s;
    int cnt[26];
};

bool cmp(const StringInfo& a, const StringInfo& b) {
    for (int i = 0; i < 26; i++) {
        if (a.cnt[i] != b.cnt[i]) 
            return a.cnt[i] > b.cnt[i];  
    }
    return a.s < b.s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<StringInfo> arr(n);
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i].s;
        memset(arr[i].cnt, 0, sizeof(arr[i].cnt));
        for (char c : arr[i].s) {
            arr[i].cnt[c - 'a']++;
        }
    }
    
    sort(arr.begin(), arr.end(), cmp);
    
    for (int i = 0; i < n; i++) {
        cout << arr[i].s << (i == n - 1 ? "\n" : " ");
    }
    
    return 0;
}