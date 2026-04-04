#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int a[100010];
int ans = 0;

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    // 枚举所有 4 个不同下标
    for(int i1 = 1; i1 <= n; i1++) {
        for(int i2 = i1 + 1; i2 <= n; i2++) {
            for(int i3 = i2 + 1; i3 <= n; i3++) {
                for(int i4 = i3 + 1; i4 <= n; i4++) {
                    // 对这 4 个下标进行全排列
                    int idx[] = {i1, i2, i3, i4};
                    do {
                        int i = idx[0], j = idx[1], k = idx[2], l = idx[3];
                        if(a[i] % a[k] == 0 && a[j] % a[l] == 0) {
                            ans++;
                        }
                    } while(next_permutation(idx, idx + 4));
                }
            }
        }
    }
    
    cout << ans << endl;
    return 0;
}