/*
* 名称：反序输出字符串

* 链接：http://985.so/kk3c
* 难度：中等
*/

#include <iostream>
#include <string>

using namespace std;

void Reverse(string& str) {
    int i = 0, j = str.size() - 1;
    while (i < j) {
        char c = str[i];
        str[i++] = str[j];
        str[j--] = c;
    }
}

int main() {
    string str;
    while (cin >> str) {
        Reverse(str);
        cout << str << endl;
    }
    return 0;
}
