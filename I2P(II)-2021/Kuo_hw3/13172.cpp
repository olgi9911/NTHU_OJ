#include<iostream>
//#include "function.h"
#include "13172.h"
using namespace std;

special_power::special_power(int n){
    this -> n = n;
}
int special_power::fpow(int x){
    return fpow(x, 880301);
}
int special_power::fpow(int x, int m){
    long long num = 1;
    for(int i = 0; i < n; i++){
        num *= x;
        num %= m;
    }
    return num;
}
int special_power::fpow(){
    long long num = 1;
    for(int i = 0; i < n; i++){
        num *= 2;
        num %= 880301;
    }
    return num;
}
string special_power::fpow(string s){
    string ret = "";
    for(int i = 0; i < s.length(); i++){
        for(int j = 0; j < n; j++){
            ret.push_back(s[i]);
        }
    }
    return ret;
}
string special_power::fpow(string s, int m){
    string ret = "";
    int count = 0;
    for(int i = 0; i < s.length(); i++){
        for(int j = 0; j < n && count < m; j++, count ++){
            ret.push_back(s[i]);
        }
    }
    return ret;
}
//Partial Judge ends
int main(){
    int x, n, m;
    string s;
    cin >> x >> n >> m >> s;
    special_power sp(n);
    cout << sp.fpow(x) << "\n";
    cout << sp.fpow(x, m) << "\n";
    cout << sp.fpow() << "\n";
    cout << sp.fpow(s) << "\n";
    cout << sp.fpow(s, m) << "\n";
}
