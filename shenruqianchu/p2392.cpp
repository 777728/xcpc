#include <iostream>
#include <climits>
#include <cmath>
using namespace std;
int xi[5];  // 存储4科的题目数量
int ti[25]; // 存储每道题的时间
int l, r;   // 左右大脑的时间
int min_diff; // 记录最小差值
int best_time; // 记录最优时间（较大大脑的时间）
int total_ans = 0; // 最终答案
void dfs(int depth,int maxdepth){
    if(depth > maxdepth){
        int current_diff = abs(l - r);
        int current_max = max(l, r);
        
        // 如果当前方案的差值更小，或者差值相同但最大值更小
        if(current_diff < min_diff || 
           (current_diff == min_diff && current_max < best_time)) {
            min_diff = current_diff;
            best_time = current_max;
        }
        return;
    }
    l += ti[depth];
    dfs(depth+1,maxdepth);
    l -= ti[depth];
    r += ti[depth];
    dfs(depth+1,maxdepth);
    r -= ti[depth];
}
int main() {
    for(int i = 1;i <= 4;++i){
        cin>>xi[i];
    }
    for(int i = 1;i <= 4;++i){
        ti[22] = {0};
        l = r = 0;
        min_diff = INT_MAX;  // 初始化为最大值
        best_time = INT_MAX; // 初始化为最大值
        for(int j = 1;j <= xi[i];j++){
            cin>>ti[j];
        }
        dfs(1,xi[i]);
        total_ans+=best_time;
    }
    cout<<total_ans;
}