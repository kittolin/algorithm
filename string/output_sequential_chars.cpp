/*
* 名称：ZOJ
* 来源：浙江大学复试上机题
* 链接：http://985.so/k2m2
* 难度：简单
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    while (cin >> str) {
        int nz = 0, no = 0, nj = 0;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == 'Z') {
                nz ++;
            } else if (str[i] == 'O') {
                no ++;
            } else {
                nj ++;
            }
        }

        int index = 0;
        while (nz > 0 || no > 0 || nj > 0) {
            if (nz-- > 0) {
                str[index++] = 'Z';
            }
            if (no-- > 0) {
                str[index++] = 'O';
            }
            if (nj-- > 0) {
                str[index++] = 'J';
            }
        }
        cout << str << endl;
    }
    return 0;
}
