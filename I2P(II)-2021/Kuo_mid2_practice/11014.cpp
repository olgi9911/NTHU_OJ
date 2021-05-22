#include <cctype>
#include <iostream>
#include <sstream>
//#include "function.h"
#include "11014.h"
//Partial judge
using namespace std;
void RleCodec::encode() {
    int count = 0;
    stringstream ss;
    char tmp = code_str[0];
    for (int i = 0; i < code_str.length() + 1; i++) {  // mind the "+ 1"
        if (code_str[i] == tmp) {
            count++;
        } else {
            if (count == 1) {
                ss << tmp;
            } else if (count == 2) {
                ss << tmp << tmp;  // "AA" instead of "2A"
            } else {
                ss << count << tmp;
            }
            tmp = code_str[i];
            count = 1;
        }
    }
    code_str = ss.str();
    //
    encoded = true;
}
void RleCodec::decode() {
    stringstream ss;
    stringstream int_ss;
    int count = 0;
    for (auto a : code_str) {
        if (isdigit(a)) {
            int_ss << a;
        } else {
            count = 0;
            int_ss >> count;
            if (count == 0) {
                ss << a;
            } else {
                while (count--) {
                    ss << a;
                }
            }
            int_ss.str("");
            int_ss.clear();
        }
    }
    code_str = ss.str();
    //
    encoded = false;
}
//
std::ostream& operator<<(std::ostream& os, Codec& data) {
    data.show(os);
    return os;
}

void encode_decode(Codec& data) {
    if (!data.is_encoded())
        data.encode();
    else
        data.decode();
}

int main() {
    std::string input_string;
    std::cin >> input_string;

    DummyCodec dummy{input_string};
    encode_decode(dummy);
    std::cout << "Dummy encoding: ";
    std::cout << dummy << std::endl;
    encode_decode(dummy);
    std::cout << "Dummy decoding: ";
    std::cout << dummy << std::endl;

    RleCodec rle{input_string};
    encode_decode(rle);
    std::cout << "RLE encoding: ";
    std::cout << rle << std::endl;
    encode_decode(rle);
    std::cout << "RLE decoding: ";
    std::cout << rle << std::endl;
}
