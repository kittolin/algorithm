/*
* 名称：密码翻译
* 来源：北京大学复试上机题
* 链接：http://985.so/ks6w
* 难度：中等
*/

#include <iostream>
#include <string>

using namespace std;

bool IsLetter(char c) {
    return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z';
}

string LetterEncryption(string str) {
    for (int i = 0; i < str.size(); i++) {
        if (IsLetter(str[i])) {
            char base = str[i] >= 'a' && str[i] <= 'z'? 'a': 'A';
            str[i] = (str[i] - base + 1) % 26 + base;
        }
    }
    return str;
}

int main() {
    string str;
    while (getline(cin, str)) {
        cout << LetterEncryption(str) << endl;
    }
    return 0;
}
