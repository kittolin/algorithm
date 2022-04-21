/*
* 名称：打牌
* 来源：北京邮电大学复试上机题
* 链接：http://985.so/9seh
* 难度：较难
*/

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int numCount[10];

bool Multiple(int number, int length) {
    for (int i = 9; i > number; i--) {
        if (numCount[i] >= length) {
            return true;
        }
    }
    return false;
}

bool Order(int number) {
    int count = 0;
    for (int i = number + 1; i <= 9; i++) {
        if (numCount[i] > 0) {
            count ++;
        } else {
            count = 0;
        }
        if (count == 5) {
            return true;
        }
    }
    return false;
}

int main() {
    string str1, str2;
    while (cin >> str1 >> str2) {
        memset(numCount, 0, sizeof(numCount));
        for (int i = 0; i < str1.size(); i++) {
            numCount[str1[i] - '0'] ++; // 对每个数字计数
        }

        bool ans;
        if (str2.size() <= 4) {
            ans = Multiple(str2[0] - '0', str2.size());
        } else {
            ans = Order(str2[0] - '0');
        }

        if (ans) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}
