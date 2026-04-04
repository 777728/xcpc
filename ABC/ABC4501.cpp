#include<iostream>
using namespace std;

int a[10] = {13,1,2,3,5,4,4,2,2,2};
int b[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

int main(){
    int cnt = 0;
    
    // 2000年到2023年
    for(int i = 2000; i < 2024; i++){
        for(int j = 1; j <= 12; j++){
            if(i % 4 == 0){ // 闰年（2000-2023范围内有效）
                b[1] = 29;
                for(int k = 1; k <= b[j-1]; k++){
                    int ans = a[i/1000] + a[(i/100)%10] + a[(i/10)%10] + a[i%10];
                    ans += a[j/10] + a[j%10];
                    ans += a[k/10] + a[k%10];
                    if(ans > 50) cnt++;
                }
                b[1] = 28;
            }
            else{
                for(int k = 1; k <= b[j-1]; k++){
                    int ans = a[i/1000] + a[(i/100)%10] + a[(i/10)%10] + a[i%10];
                    ans += a[j/10] + a[j%10];
                    ans += a[k/10] + a[k%10];
                    if(ans > 50) cnt++;
                }
            }
        }
    }
    
    // 2024年1-3月
    for(int j = 1; j <= 3; j++){
        b[1] = 29;
        for(int k = 1; k <= b[j-1]; k++){
            int ans = a[2] + a[0] + a[2] + a[4]; // 2024
            ans += a[j/10] + a[j%10];
            ans += a[k/10] + a[k%10];
            if(ans > 50) cnt++;
        }
    }
    
    // 2024年4月1-13日
    for(int k = 1; k <= 13; k++){
        int ans = a[2] + a[0] + a[2] + a[4]; // 2024
        ans += a[0] + a[4]; // 04月
        ans += a[k/10] + a[k%10];
        if(ans > 50) cnt++;
    }
    
    cout << cnt << endl;
    return 0;
}