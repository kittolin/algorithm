/*
* 名称：键盘错误输入的字符串解码

* 链接：http://985.so/90ay
* 难度：简单
*/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<char, char> keyMap;

void InitialKeyMap() {
    string keys = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./"; // '\' 斜杆字符需要转义
    for (int i = 1; i < keys.size(); i++) {
        keyMap[keys[i]] = keys[i - 1];
    }
}

int main() {
    InitialKeyMap();
    string input;
    while (getline(cin, input)) {
        for (int i = 0; i < input.size(); i++) {
            if (input[i] != ' ') {
                input[i] = keyMap[input[i]];
            }
        }
        cout << input << endl;
    }
    return 0;
}
