#include<iostream>
#include<algorithm>
using namespace std;
//#define long long ll 
bool is_prime(int x){
	if(x == 1)return 1;
	else{
		for(int i = 2;i * i <= x;i++){
			if(x % i == 0)return 0;
		}
		return 1;
	}
}
bool is_hui(int x){
	string s = to_string(x);
	int l = 0,r = s.size() - 1;
	for(int i = l;i <= r;i++){
		if(s[i] != s[r])return 0;
		r--;
	}
	return 1;
}
signed main(){
	int a,b;
	cin>>a>>b;
	if(a % 2 == 0)a++;
	for(int i = a;i <= b;i+=2){
		if(is_hui(i)){
			if(is_prime(i)){
				cout<<i<<endl;
			}
		}
	}
}
