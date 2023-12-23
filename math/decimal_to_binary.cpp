/*
* 名称：二进制数

* 链接：http://t.cn/AiCuKTOv
* 难度：中等
*/

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

char Int2Char(int i) {
    if (i < 10) {
        return i + '0';
    }
    return i - 10 + 'A';
}

string Decimal2N(int decimal, int n) {
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
    int decimal;
    while (cin >> decimal) {
        cout << Decimal2N(decimal, 2) << endl;
    }
    return 0;
}
