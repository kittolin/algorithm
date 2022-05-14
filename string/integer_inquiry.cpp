/*
* 名称：Integer Inquiry (大数加法)
* 来源：北京大学复试上机题
* 链接：http://985.so/xvi5
* 难度：简单
*/

#include <iostream>
#include <string>

using namespace std;

const int MAXN = 100 + 10;

char result[MAXN];

void Addition(string str) {
    int index = MAXN - 1, carry = 0;
    for (int i = str.size() - 1; i >= 0 ; i--) {
        int sum = str[i] - '0' + result[index] - '0' + carry;
        result[index--] = sum % 10 + '0';
        carry = sum / 10;
    }
    while (carry) {
        int sum = result[index] - '0' + carry;
        result[index--] = sum % 10 + '0';
        carry = sum / 10;
    }
}

int main() {
    fill(result, result + MAXN, '0');
    string str;
    while (cin >> str) {
        if (str == "0") {
            break;
        }
        Addition(str);
    }

    int index = 0;
    // 跳过前导 0
    while (result[index] == '0') {
        index ++;
    }
    printf("%s\n", result + index);
    return 0;
}
