#include <iostream>
#include <string>
#include <queue>
#include <map>
using namespace std;

string a, b;
queue<string> q;
map<string, int> dis;  // 记录到达每个字符串的步数
struct change {
    string l;
    string r;
} c[7];

int main() {
    cin >> a >> b;
    int cnt = 1;
    while (cin >> c[cnt].l >> c[cnt].r) {
        cnt++;
    }
    cnt--;  // 实际规则数量
    
    q.push(a);
    dis[a] = 0;
    
    while (!q.empty()) {
        string tmpa = q.front();
        q.pop();
        int step = dis[tmpa];
        
        if (step > 10) {
            cout << "NO ANSWER!";
            return 0;
        }
        if (tmpa == b) {
            cout << step;
            return 0;
        }
        
        // 遍历所有规则
        for (int j = 1; j <= cnt; j++) {
            int pos = 0;
            // 查找所有可匹配的位置
            while ((pos = tmpa.find(c[j].l, pos)) != string::npos) {
                // 生成新字符串
                string tmp2 = tmpa.substr(0, pos) + 
                             c[j].r + 
                             tmpa.substr(pos + c[j].l.length());
                
                // 如果这个状态没访问过
                if (!dis.count(tmp2)) {
                    dis[tmp2] = step + 1;
                    q.push(tmp2);
                }
                
                pos++;  // 继续查找下一个匹配位置
            }
        }
    }
    
    cout << "NO ANSWER!";
    return 0;
}