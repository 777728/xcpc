#include<iostream>
#include<cstring>
using namespace std;
int A,B,C;
int b[11];
bool found = 0;

void beforecheck(int n){
    b[n % 10] = 1;
    b[n / 10 % 10] = 1;
    b[n / 100] = 1;
}

bool check(){
    for(int i = 1;i <= 9;i++){
        if(!b[i]) return 0;
    }
    return 1;
}

int main(){
    cin>>A>>B>>C;
    if(A==0){
        cout<<"No!!!";
        return 0;
    }
    for(int i = 123;i <= 987;++i){
        // 确保整数运算精度
        if(i * B % A != 0 || i * C % A != 0) continue;
        
        int n1 = i;
        int n2 = i * B / A;
        int n3 = i * C / A;
        
        // 检查是否是三位数
        if(n2 >= 123 && n2 <= 987 && n3 >= 123 && n3 <= 987&&A&&B&&C){
            memset(b,0,sizeof(b));
            beforecheck(n1);
            beforecheck(n2);
            beforecheck(n3);
            
            if(check()) {
                found = 1;
                cout<<n1<<" "<<n2<<" "<<n3<<endl;
            }
        }
    }
    
    if(!found) cout<<"No!!!";
    return 0;
}