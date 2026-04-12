    #include <iostream>
    #include <random>   // 修复：引入 mt19937
    #include <chrono>   // 修复：引入 chrono
    
    using namespace std;
    
    int main()
    { 
        // 使用 std::chrono 和 std::mt19937
        std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
        
        int n = rng() % 10 + 1;
        
        for(int i = 1; i <= n; i++){
            cout << (rng() % 10 + 1) << " ";
        }
        
        cout << endl;
        
        return 0;
    }