/*
* 名称：十六进制转换成十进制

* 链接：http://985.so/wmhc
* 难度：较难
*/

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int Char2Int(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    }
    if (c >= 'a' && c <= 'z') {
        return c - 'a' + 10;
    }
    if (c >= 'A' && c <= 'Z') {
        return c - 'A' + 10;
    }
    return -1;  // 非法字符
}

// 字符串 s 是 m 进制的
int M2Decimal(string s, int m) {
    // 十六进制数截断 0x 或 0X
    if (m == 16 && (s.substr(0, 2) == "0x" || s.substr(0, 2) == "0X")) {
        s = s.substr(2);
    }
    // 八进制数截断 0
    if (m == 8 && s.size() > 1 && s.substr(0, 1) == "0") {
        s = s.substr(1);
    }

    int decimal = 0;
    for (int i = 0; i < s.size(); i ++) {
        decimal = decimal * m + Char2Int(s[i]);
    }
    return decimal;
}

int main() {
    string hex;
    while (cin >> hex) {
        cout << M2Decimal(hex, 16) << endl;
    }
    return 0;
}
