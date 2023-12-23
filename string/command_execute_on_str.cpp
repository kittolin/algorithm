/*
* 名称：输入指令对字符串进行操作

* 链接：http://985.so/9nh6
* 难度：困难
*/

#include <iostream>
#include <string>

using namespace std;

string Reverse(string str, int start, int length) {
    int i = start, j = start + length - 1;
    // 从外向内头尾两两互换
    while (i <= j) {
        char c = str[i];
        str[i++] = str[j];
        str[j--] = c;
    }
    return str;
}

string Replace(string str, int start, int length, string newStr) {
    return str.substr(0, start) + newStr + str.substr(start + length);
}

int main() {
    string str, command;
    int n;
    while (cin >> str) {
        cin >> n;
        while (n --) {
            cin >> command;
            if (command[0] == '0') {
                str = Reverse(str, command[1] - '0', command[2] - '0');
            } else {
                str = Replace(str, command[1] - '0', command[2] - '0', command.substr(3));
            }
            cout << str << endl;
        }
    }
    return 0;
}
