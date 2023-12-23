/*
* 名称：IP 地址

* 链接：http://985.so/96u7
* 难度：较难
*/

#include <iostream>
#include <string>

using namespace std;

bool IsValidIP(string ip) {
    int numbers = 0, points = 0, index = 0;
    while (index < ip.size()) {
        if (isdigit(ip[index])) {
            int num = 0;
            // 提取数字进行判断，注意最后一个数字的 index 越界问题
            while (index < ip.size() && isdigit(ip[index])) {
                num = num * 10 + ip[index] - '0';
                index ++;
            }
            if (num < 0 || num > 255) {
                return false;
            }
            numbers ++;
        } else if (ip[index] == '.') {
            points ++;
            index ++;
        } else {
            return false;
        }
    }

    return numbers == 4 && points == 3;
}

int main() {
    string ip;
    while (cin >> ip) {
        if (IsValidIP(ip)) {
            cout << "Yes!" << endl;
        } else {
            cout << "No!" << endl;
        }
    }
    return 0;
}
