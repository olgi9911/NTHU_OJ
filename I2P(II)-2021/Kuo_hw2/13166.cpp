#include<iostream>
//#include"function.h"
#include "13166.h"
using namespace std;

big_number::big_number(string num){
    this -> num = num;
}

bool big_number::multiple_of_two(){
    int length = num.length();
    if(num[length - 1] - '0' % 2 == 0) return true;
    else return false;
}
bool big_number::multiple_of_three(){
    int length = num.length();
    int sum = 0;
    for(int i = 0; i < length; i++){
        sum += num[i] - '0';
    }
    if(sum % 3 == 0) return true;
    else return false;
}
bool big_number::multiple_of_four(){
    int length = num.length();
    int last = num[length - 1] - '0';
    int pre = num[length - 2] - '0';
    int sum = last + pre * 10;
    if(sum % 4 == 0) return true;
    else return false;
}
bool big_number::multiple_of_five(){
    int length = num.length();
    int last = num[length - 1] - '0';
    if(last == 0 || last == 5) return true;
    else return false;
}
bool big_number::multiple_of_six(){
    bool two, three;
    two = big_number::multiple_of_two();
    three = big_number::multiple_of_three();
    if(two && three) return true;
    else return false;
}
bool big_number::multiple_of_eight(){
    int length = num.length();
    int last = num[length - 1] -'0';
    int last2 = num[length - 2] -'0';
    int last3 = num[length - 3] -'0';
    int sum = last + last2 * 10 + last3 * 100;
    if(sum % 8 == 0) return true;
    else return false;
}
bool big_number::multiple_of_nine(){
    int length = num.length();
    int sum = 0;
    for(int i = 0; i < length; i++){
        sum += num[i] - '0';
    }
    if(sum % 9 == 0) return true;
    else return false;
}
bool big_number::multiple_of_ten(){
    int length = num.length();
    int last = num[length - 1] -'0';
    if(last == 0 && length > 1) return true;
    else return false;
}
bool big_number::multiple_of_eleven(){
    int length = num.length();
    int idx = 0;
    int sum = 0;
    for(int i = 0; i < length; i++){
        if(idx % 2){
            sum -= (num[i] - '0');
        } else{
            sum += (num[i] - '0');
        }
        idx ++;
    }
    if(sum % 11 == 0) return true;
    else return false;
}

int main(){
    int t, n;
    string x;
    cin >> t;
    while(t--){
        cin >> x >> n;
        big_number number = {x};
        if (n == 2) {
            if (number.multiple_of_two()){
                cout << "Yes\n";
            }else {
                cout << "No\n";
            }
        }
        if (n == 3) {
            if (number.multiple_of_three()){
                cout << "Yes\n";
            }else {
                cout << "No\n";
            }
        }
        if (n == 4) {
            if (number.multiple_of_four()){
                cout << "Yes\n";
            }else {
                cout << "No\n";
            }
        }
        if (n == 5) {
            if (number.multiple_of_five()){
                cout << "Yes\n";
            }else {
                cout << "No\n";
            }
        }
        if (n == 6) {
            if (number.multiple_of_six()){
                cout << "Yes\n";
            }else {
                cout << "No\n";
            }
        }
        if (n == 8) {
            if (number.multiple_of_eight()){
                cout << "Yes\n";
            }else {
                cout << "No\n";
            }
        }
        if (n == 9) {
            if (number.multiple_of_nine()){
                cout << "Yes\n";
            }else {
                cout << "No\n";
            }
        }
        if (n == 10) {
            if (number.multiple_of_ten()){
                cout << "Yes\n";
            }else {
                cout << "No\n";
            }
        }
        if (n == 11) {
            if (number.multiple_of_eleven()){
                cout << "Yes\n";
            }else {
                cout << "No\n";
            }
        }
    }
}
