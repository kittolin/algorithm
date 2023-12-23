/*
* 名称：大浮点数加法

* 链接：http://985.so/xi4v
* 难度：简单
*/

#include <iostream>
#include <string>

using namespace std;

// 添加前导 0 和后导 0，使得两字符串长度相同且小数点对齐
void FillZero(string& str1, string& str2) {
    int base1 = str1.find('.');
    int base2 = str2.find('.');
    int places1 = str1.size() - 1 - base1;  // 小数位长度
    int places2 = str2.size() - 1 - base2;

    string prefix(abs(base1 - base2), '0');
    if (base1 > base2) {
        str2 = prefix + str2;
    } else if (base1 < base2) {
        str1 = prefix + str1;
    }

    string suffix(abs(places1 - places2), '0');
    if (places1 > places2) {
        str2 += suffix;
    } else if (places1 < places2) {
        str1 += suffix;
    }
}

string Addition(string str1, string str2) {
    FillZero(str1, str2);
    string result(str1.size(), '0');
    int carry = 0, index = result.size() - 1;
    // 从后往前逐位相加
    for (int i = str1.size() - 1; i >= 0; i--) {
        if (str1[i] == '.') {
            result[index--] = '.';
        } else {
            int sum = str1[i] - '0' + str2[i] - '0' + carry;
            result[index--] = sum % 10 + '0';
            carry = sum / 10;
        }
    }
    // 最高位有进位
    if (carry) {
        result = "1" + result;
    }

    // int i = 0, j = result.size() - 1;
    // while (result[i] == '0') {  // 跳过前导 0
    //     i++;
    // }
    // if (result[i] == '.') {     // 保证小数点前有一个整数位
    //     i--;
    // }
    // while (result[j] == '0') {  // 跳过后导 0
    //     j--;
    // }
    return result;
}

int main() {
    string str1, str2;
    while (cin >> str1 >> str2) {
        cout << Addition(str1, str2) << endl;
    }
    return 0;
}
