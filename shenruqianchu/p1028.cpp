#include <iostream>
#include <vector>
using namespace std;

int n, cnt = 0;
vector<int> seq;

void dfs(int last) {
    // 输出当前序列
    for (int i = 0; i < seq.size(); i++) {
        if (i > 0) cout << ", ";
        cout << seq[i];
    }
    cout << endl;

    // 枚举下一个可加的数
    for (int next = last / 2; next >= 1; next--) {
        seq.push_back(next);//选它
        dfs(next);
        seq.pop_back();//不选它
    }
}

int main() {
    cin >> n;
    seq.push_back(n);
    dfs(n);
    return 0;
}