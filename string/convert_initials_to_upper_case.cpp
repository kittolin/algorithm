/*
* 名称：首字母大写
* 来源：北京大学复试上机题
* 链接：http://985.so/kugg
* 难度：较难
*/

#include <iostream>
#include <string>

using namespace std;

bool IsLetter(char c) {
    return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9';
}

char UpperCase(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 32;
    }
    return c;
}

void ConvertInitialsUpperCase(string& text) {
    if (text.size() == 0) {
        return;
    }
    if (IsLetter(text[0])) {
        text[0] = UpperCase(text[0]);
    }

    int index = 1;
    while (index < text.size()) {
        if (IsLetter(text[index])) {
            index ++;
        } else {
            while (++index < text.size() && !IsLetter(text[index])); // 跳过连续多个非字母数字的字符，注意防止末尾的句号越界
            if (index < text.size()) {
                text[index] = UpperCase(text[index]);
            }
        }
    }
}

int main() {
    string text;
    while (getline(cin, text)) {
        ConvertInitialsUpperCase(text);
        cout << text << endl;
    }
    return 0;
}
