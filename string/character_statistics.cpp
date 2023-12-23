/*
* 名称：统计字符

* 链接：http://t.cn/Ai8fvq4I
* 难度：简单
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <unordered_map>

using namespace std;

void CharStatistics(string str1, string str2) {
    unordered_map<char, int> map;
    for (int i = 0; i < str2.size(); i++) {
        map[str2[i]] ++;
    }
    for (int i = 0; i < str1.size(); i++) {
        printf("%c %d\n", str1[i], map[str1[i]]);
    }
}

int main() {
    string str1, str2;
    while (getline(cin, str1)) {
        if (str1 == "#") {
            break;
        }
        getline(cin, str2);
        CharStatistics(str1, str2);
    }
    return 0;
}
