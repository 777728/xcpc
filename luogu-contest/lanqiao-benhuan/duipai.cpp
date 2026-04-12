#include <string>
#include <iostream>
#include <cstdlib>  // for system()
using namespace std;

int main() {
    // 编译程序（macOS 使用 g++，路径通常为 /usr/bin/g++ 或直接用 g++）
    system("g++ -std=c++11 generator.cpp -o generator");
    system("g++ -std=c++11 brute.cpp -o brute");
    system("g++ -std=c++11 std.cpp -o std");

    while (true) {
        // 生成测试数据
        system("./generator > data.txt");

        // 运行暴力程序和标准程序
        system("./brute < data.txt > brute.txt");
        system("./std < data.txt > std.txt");

        // 比较输出结果
        if (system("diff brute.txt std.txt") != 0) {
            cout << "Wrong Answer" << endl;
            system("cat data.txt");
            system("cat brute.txt");
            system("cat std.txt");
            break;
        } else {
            cout << "Accepted" << endl;
        }
    }

    return 0;
}