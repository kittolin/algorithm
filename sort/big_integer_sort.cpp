/*
* 名称：大整数排序

* 链接：http://985.so/kt2j
* 难度：困难
* 分析：用字符串代替大整数
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int MAXN = 100 + 10;
string arr[MAXN];

bool Compare(string str1, string str2) {
    if (str1.size() == str2.size()) {
        return str1 < str2;
    }
    return str1.size() < str2.size();
}

int main() {
    int n;
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        sort(arr, arr + n, Compare);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << endl;
        }
    }
    return 0;
}
