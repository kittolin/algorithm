/*
* 名称：按字典序输出每个子串出现的次数(大于 1 次的)
* 来源：北京大学复试上机题
* 链接：http://985.so/xtpq
* 难度：简单
* 分析：map 底层数据结构是红黑树，元素本身就是有序的
*/

#include <iostream>
#include <string>
#include <map>

using namespace std;

void PrintSubStrCount(string str) {
    map<string, int> substrMap;
    for (int i = 0; i < str.size(); i++) {
        // 从当前字符开始循环往前截取每一个子串
        for (int j = i; j >= 0; j--) {
            substrMap[str.substr(j, i - j + 1)] ++;
        }
    }

    for (auto& pair: substrMap) {
        if (pair.second > 1) {
            cout << pair.first << " " << pair.second << endl;
        }
    }
}

int main() {
    string str;
    while (cin >> str) {
        PrintSubStrCount(str);
    }
    return 0;
}
