/*
* 名称：回文字符串

* 链接：http://985.so/9vz4
* 难度：较难
*/

#include <iostream>
#include <string>

using namespace std;

bool IsPalindrome(string str) {
    int i = 0, j = str.size() - 1;
    while (i < j) {
        if (str[i++] != str[j--]) {
            return false;
        }
    }
    return true;
}

int main() {
    string str;
    while(getline(cin, str)) {
        if (IsPalindrome(str)) {
            printf("Yes!\n");
        } else {
            printf("No!\n");
        }
    }
    return 0;
}
