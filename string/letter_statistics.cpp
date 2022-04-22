/*
* 名称：字母统计
* 来源：上海交通大学复试上机题
* 链接：http://985.so/9zm3
* 难度：简单
*/

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

const int N = 26;

int letterCount[N];

int main() {
    string str;
    while (cin >> str) {
        memset(letterCount, 0, sizeof(letterCount));
        for (int i = 0; i < str.size(); i++) {
            if (str[i] >= 'A' && str[i] <= 'Z') {
                letterCount[str[i] - 'A'] ++;
            }
        }
        for (int i = 0; i < N; i++) {
            printf("%c:%d\n", i + 'A', letterCount[i]);
        }
    }
    return 0;
}
