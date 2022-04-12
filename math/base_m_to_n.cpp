/*
* 名称：M 进制转换成 N 进制
* 来源：清华大学复试上机题
* 链接：http://t.cn/AiCuKG7E
* 难度：中等
* !!! 用 int 会溢出，导致错误的结果
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

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

char Int2Char(int i) {
    if (i < 10) {
        return i + '0';
    }
    return i - 10 + 'a';
}

// 字符串 s 是 m 进制的
long long M2Decimal(string s, int m) {
    // 十六进制数截断 0x 或 0X
    if (m == 16 && (s.substr(0, 2) == "0x" || s.substr(0, 2) == "0X")) {
        s = s.substr(2);
    }
    // 八进制数截断 0
    if (m == 8 && s.size() > 1 && s.substr(0, 1) == "0") {
        s = s.substr(1);
    }

    long long decimal = 0;
    for (int i = 0; i < s.size(); i ++) {
        decimal = decimal * m + Char2Int(s[i]);
    }
    return decimal;
}

string Decimal2N(long long decimal, int n) {
    if (decimal == 0) {
        return "0";
    }
    vector<char> v;
    while (decimal != 0) {
        v.push_back(Int2Char(decimal % n));
        decimal /= n;
    }
    string ans = "";
    for (int i = v.size() - 1; i >= 0; i--) {
        ans += v[i];
    }
    return ans;
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    string str;
    cin >> str;
    long long decimal = M2Decimal(str, m);
    cout << Decimal2N(decimal, n) << endl;
    return 0;
}
