/*
* 名称：数制转换
* 来源：北京大学复试上机题
* 链接：http://985.so/k4ja
* 难度：中等
* !!! 注意字符和数字的转换
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int Char2Int(char c) {
    if (c >= 'A' && c <= 'F') {
        return c - 'A' + 10;
    } else if (c >= 'a' && c <= 'f') {
        return c - 'a' + 10;
    } else {
        return c - '0';
    }
}

char Int2Char(int i) {
    if (i > 9) {
        return i - 10 + 'A';
    }
    return i + '0'; // !!! 返回 i 的话不会报错，但在组成字符串时里面的字符是控制字符 
}

long ConvertToDecimal(string str, int from) {
    long decimal = 0;
    int base = 1;
    for (int i = str.size() - 1; i >= 0; i--) {
        decimal += Char2Int(str[i]) * base;
        base *= from;
    }
    return decimal;
}

string ConvertFromDecimal(long number, int to) {
    vector<char> digits;
    while (number) {
        digits.push_back(Int2Char(number % to));
        number /= to;
    }
    int size = digits.size();
    string ans(size, ' ');
    for (int i = 0; i < size; i++) {
        ans[i] = digits[size - 1 - i];
    }
    return ans;
}

string ConvertBase(string str, int from, int to) {
    long number = ConvertToDecimal(str, from);
    return ConvertFromDecimal(number, to);
}

int main() {
    int from, to;
    string str;
    while (cin >> from >> str >> to) {
        cout << ConvertBase(str, from, to) << endl;
    }
    return 0;
}
