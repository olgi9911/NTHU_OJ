#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    int num = 0;
    cin >> s;
    for(int i = 0; i < s.length(); i++){
        int second = i + 1, third = i + 2;
        if(second < s.length() && s[i] == s[second] && s[i] != 'X' && s[second] != 'X')
            num ++, s[second] = 'X';
        if(third < s.length() && s[i] == s[third] && s[i] != 'X' && s[third] != 'X')
            num ++, s[third] = 'X';
    }
    cout << num << endl;
}