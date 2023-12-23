/*
* 名称：字符串表示形式的整数相加

* 链接：http://985.so/9c4g
* 难度：中等
*/

#include <iostream>
#include <string>

using namespace std;

int ConvertStr2Int(string str) {
    int number = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            number = number * 10 + str[i] - '0';
        }
    }
    return str[0] == '-'? -1 * number: number;
}

int main() {
    string a, b;
    while (cin >> a >> b) {
        cout << ConvertStr2Int(a) + ConvertStr2Int(b) << endl; 
    }
    return 0;
}
