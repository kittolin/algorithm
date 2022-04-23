/*
* 名称：奇校验
* 来源：华中科技大学复试上机题
* 链接：http://985.so/9vej
* 难度：简单
*/

#include <iostream>
#include <string>

using namespace std;

// 将字符转换成二进制的 ASCII 码，根据 ASCII 码中 1 的个数来决定高位补 0 还是 1
string OddParity(char c) {
    string ans(8, '0');
    int ascii = c - '\0', index = 7, count = 0;
    while (ascii) {
        if (ascii % 2 == 1) {
            count ++;
        }
        ans[index--] = ascii % 2 + '0';
        ascii /= 2;
    }
    if (count % 2 == 0) {
        ans[0] = '1';
    }
    return ans;
}

int main() {
    string str;
    while (cin >> str) {
        for (int i = 0; i < str.size(); i++) {
            cout << OddParity(str[i]) << endl;
        }
    }
    return 0;
}
