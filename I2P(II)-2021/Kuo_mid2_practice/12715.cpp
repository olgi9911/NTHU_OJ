#include <algorithm>
#include <cstdio>
#include <cstring>
//#include "function.h"
#include "12715.h"

using namespace oj;
//Partial judge
void reverse(char *s) {
    int len = strlen(s);
    for (int i = 0; i < len / 2; i++) {
        std::swap(s[i], s[len - 1 - i]);
    }
}

BigInt::BigInt(char *s) {
    _val = new char[strlen(s) + 1];
    strcpy(_val, s);
}
BigInt::~BigInt() {
    delete[] _val;
}
BigInt &BigInt::operator++() {  // ++B
    reverse(_val);
    int len = strlen(_val);
    _val[0]++;
    for (int i = 0; i < len; i++) {
        if (_val[i] > '9') {  // Carry
            _val[i] = '0';
            if (i == len - 1) {  // Handling new bit
                _val[i + 1] = '1';
                len++;
            } else {
                _val[i + 1]++;
            }
        }
    }
    _val[len] = '\0';
    reverse(_val);
    return *this;
}
BigInt BigInt::operator++(int) {  // B++
    BigInt temp = _val;
    //operator++();
    ++(*this);
    return temp;
}
BigInt &BigInt::operator--() {
    if (strlen(_val) == 1 && _val[0] == '0') {
        return *this;
    }

    int idx = strlen(_val) - 1;
    while (idx >= 0) {
        _val[idx]--;
        if (_val[idx] < '0') {  // e.g. 10000 -> 9999
            _val[idx] = '9';
            idx--;
        } else {
            break;
        }
    }

    if (_val[0] == '0' && _val[1] != '\0') {  //not 0
        char *old = _val;
        _val = new char[strlen(_val)];
        strcpy(_val, old + 1);  // Skip leading zero
        delete[] old;
    }

    return *this;
}
BigInt BigInt::operator--(int) {
    BigInt temp = _val;
    operator--();
    return temp;
}
char *BigInt::to_s() {
    return _val;
}
//
int main() {
    static char s[1024];

    int T;
    std::scanf("%d", &T);
    while (T--) {
        scanf("%s", s);
        BigInt B(s);

        int Q;
        std::scanf("%d", &Q);

        while (Q--) {
            char op[5];
            scanf("%s", op);
            if (!strcmp(op, "++B"))
                std::printf("%s\n", (++B).to_s());
            if (!strcmp(op, "B++"))
                std::printf("%s\n", (B++).to_s());
            if (!strcmp(op, "--B"))
                std::printf("%s\n", (--B).to_s());
            if (!strcmp(op, "B--"))
                std::printf("%s\n", (B--).to_s());
        }
    }

    return 0;
}
