/*
* 名称：简单密码

* 链接：http://t.cn/Ai8bih2z
* 难度：简单
*
* 算法：(i - 5 + 26) % 26
*               密文:    A   B   C   D   E   F  ... U   V   W   X   Y   Z 
*                 i:    0   1   2   3   4   5  ... 20  21  22  23  24  25
*             i - 5:    -5  -4  -3  -2  -1  0  ... 15  16  17  18  19  20 
*        i - 5 + 26:    21  22  23  24  25  26 ... 41  42  43  44  45  46
* (i - 5 + 26) % 26:    21  22  23  24  25  0  ... 15  16  17  18  19  20
*               明文:    V   W   X   Y   Z   A  ... P   Q   R   S   T   U
*/

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

string decrypt(string str) {
    for (int i = 0; i < str.size(); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = (str[i] - 'A' - 5 + 26) % 26 + 'A';
        }
    }
    return str;
}

int main() {
    string str;
    while (getline(cin, str)) {
        if (str == "ENDOFINPUT") {
            break;
        }
        getline(cin, str);
        cout << decrypt(str) << endl;
        getline(cin, str);
    }
    return 0;
}
