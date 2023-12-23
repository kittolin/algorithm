/*
* 名称：后缀子串排序

* 链接：http://985.so/9z1g
* 难度：入门
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string str;
    while (cin >> str) {
        int size = str.size();
        string substrs[size];
        for (int i = 0; i < size; i++) {
            substrs[i] = str.substr(i);
        }
        sort(substrs, substrs + size);
        for (int i = 0; i < size; i++) {
            cout << substrs[i] << endl;
        }
    }
    return 0;
}
