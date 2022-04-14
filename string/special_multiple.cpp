/*
* 名称：特殊乘法
* 来源：清华大学复试上机题
* 链接：﻿http://t.cn/Ai8by9vW
* 难度：简单
*/

#include <iostream>
#include <cstdio>
#include <string>       // C++
// #include <cstring>   // C, eg: strlen

using namespace std;

int SpecialMultiple(string str1, string str2) {
    int ans = 0;
    for (int i = 0; i < str1.size(); i++) {
        for (int j = 0; j < str2.size(); j++) {
            ans += (str1[i] - '0') * (str2[j] - '0');
        }
    }
    return ans;
}

int main() {
    string str1, str2;
    while (cin >> str1 >> str2) {
        cout << SpecialMultiple(str1, str2) << endl;
    }
    return 0;
}
