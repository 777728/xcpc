#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
#define maxn 1010
const int mod = 1000000007;
int a[10] = {13,1,2,3,5,4,4,2,2,2};//38
int b[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
int main(){
    int ans = 0;
    int cnt = 0;
    for(int i = 2000;i < 2024;i++){
        for(int j = 1;j <= 12;j++){
            if(i % 4 == 0){
                b[1] = 29;
                for(int k = 1;k <= b[j-1];k++){
                ans = 0;
                ans = a[i/1000] + a[(i / 100) % 10] + a[(i / 10)%10] + a[i%10];//nian
                ans += a[j / 10] + a[j % 10];//yue
                ans += a[k / 10] + a[k % 10];//ri
                if(ans > 50)cnt++;
                }
                b[1] = 28;
                }
            else{
                for(int k = 1;k <= b[j-1];k++){
                ans = 0;
                ans = a[i/1000] + a[(i / 100) % 10] + a[(i / 10)%10] + a[i%10];//nian
                ans += a[j / 10] + a[j % 10];//yue
                ans += a[k / 10] + a[k % 10];//ri
                if(ans > 50)cnt++;
                }
            }
        }
    }
    for(int j = 1;j <= 3;j++){
                b[1] = 29;
                for(int k = 1;k <= b[j-1];k++){
                ans = 0;
                ans += a[2024/1000] + a[(2024 / 100) % 10] + a[(2024 / 10)%10] + a[2024%10];//nian
                ans += a[j / 10] + a[j % 10];//yue
                ans += a[k / 10] + a[k % 10];//ri
                if(ans > 50)cnt++;
                }    
        }
    ans = 0;
    //ans += (a[2024/1000] + a[(2024 / 100) % 10] + a[(2024 / 10)%10] + a[2024%10]) + 18
    cout<<cnt + 10<<endl;
}