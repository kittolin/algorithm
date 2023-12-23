/*
* 名称：最长 & 最短文本

* 链接：http://985.so/9v1j
* 难度：中等
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<string> strs;
    string str;
    int shortest = 1000 + 1, longest = 0;   // 这样设置可以保证第一个字符串能通过长度检测
    while (getline(cin, str)) {
        int size = str.size();
        if (size > shortest && size < longest) {  // 长度在 s ~ l 之间的字符串已经没必要输入了，减少点空间
            continue;
        }
        strs.push_back(str);
        shortest = min(shortest, size);
        longest = max(longest, size);
    }

    for (int i = 0; i < strs.size(); i++) {
        if (strs[i].size() == shortest) {
            cout << strs[i] << endl;
        }
    }
    for (int i = 0; i < strs.size(); i++) {
        if (strs[i].size() == longest) {
            cout << strs[i] << endl;
        }
    }
    return 0;
}
