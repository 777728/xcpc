#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

int p1, p2, p3;
string s, res;

void expand(char l, char r) {
    string mid;
    for (char c = l + 1; c < r; ++c) {
        char ch = (p1 == 3) ? '*' : c;
        if (p1 == 2 && isalpha(c)) ch = toupper(c);
        mid += string(p2, ch);
    }
    if (p3 == 2) reverse(mid.begin(), mid.end());
    res += mid;
}

int main() {
    cin >> p1 >> p2 >> p3 >> s;
    for (size_t i = 0; i < s.size(); ++i) {
        if (s[i] == '-' && i > 0 && i + 1 < s.size()) {
            char l = s[i-1], r = s[i+1];
            bool sameType = (isdigit(l) && isdigit(r)) || (islower(l) && islower(r));
            if (sameType && r > l) {
                if (r > l + 1) expand(l, r);
                continue; // 满足条件则跳过 '-'
            }
        }
        res += s[i];
    }
    cout << res;
    return 0;
}