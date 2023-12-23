/*
* 名称：字符串的字母字符忽略大小写排序

* 链接：http://985.so/xftm
* 难度：困难
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

char UpperCase(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 'a' + 'A';
    }
    return c;
}

bool IsAlphabet(char c) {
    return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z';
}

// 字母全部转大写比较
bool Compare(char c1, char c2) {
    return UpperCase(c1) < UpperCase(c2);
}

string SortAlphabets(string str) {
    vector<char> vec;
    // 只对字符串中的英文字母排序
    for (int i = 0; i < str.size(); i++) {
        if (IsAlphabet(str[i])) {
            vec.push_back(str[i]);
        }
    }
    stable_sort(vec.begin(), vec.end(), Compare);

    // 将排好序后的英文字母重新填回原字符串
    int index = 0;
    for (int i = 0; i < str.size(); i++) {
        if (IsAlphabet(str[i])) {
            str[i] = vec[index++];
        }
    }
    return str;
}

int main() {
    string str;
    while (getline(cin, str)) {
        cout << SortAlphabets(str) << endl;
    }
    return 0;
}
