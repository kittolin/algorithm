/*
* 名称：Skew 数
* 来源：北京大学复试上机题
* 链接：http://985.so/kagp
* 难度：入门
*/

#include <iostream>
#include <string>

using namespace std;

int Skew2Decimal(string str) {
    int decimal = 0, base = 2;
    for (int i = str.size() - 1; i >= 0; i--) {
        decimal += (str[i] - '0') * (base - 1);
        base *= 2;
    }
    return decimal;
}

int main() {
    string str;
    while (cin >> str) {
        cout << Skew2Decimal(str)<< endl;
    }
    return 0;
}
