/*
* 名称：Primary Arithmetic
* 来源：北京大学复试上机题
* 链接：http://985.so/k4wd
* 难度：中等
*/

#include <iostream>
#include <string>

using namespace std;

int NumOfAdditionCarry(string str1, string str2) {
    int i = str1.size() - 1, j = str2.size() - 1, count = 0, carry = 0;
    char c1, c2;
    // 从后往前逐位相加，如果两字符串长度不相等，则短的用字符 '0' 代替
    while (i >= 0 || j >= 0) {
        c1 = i >= 0? str1[i--]: '0';
        c2 = j >= 0? str2[j--]: '0';
        carry = (c1 - '0' + c2 - '0' + carry) / 10;
        if (carry) {
            count ++;
        }
    }
    return count;
}

int main() {
    string str1, str2;
    while (cin >> str1 >> str2) {
        if (str1 == "0" && str2 == "0") {
            break;
        }
        int count = NumOfAdditionCarry(str1, str2);
        if (count > 1) {
            printf("%d carry operations.\n", count);
        } else if (count == 1) {
            printf("%d carry operation.\n", count);
        } else {
            printf("NO carry operation.\n");
        }
    }
    return 0;
}
