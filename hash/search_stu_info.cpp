/*
* 名称：查找学生信息
* 来源：清华大学复试上机题
* 链接：http://t.cn/AiCuVIuY
* 难度：中等
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    getchar();  // 吃掉回车
    unordered_map<string, string> map;
    while (n --) {
        string info;
        getline(cin, info); // 读取一整行字符串
        int pos = info.find(" ");
        map[info.substr(0, pos)] = info;
    }

    int m;
    scanf("%d", &m);
    while (m --) {
        string key;
        cin >> key;
        string info = map[key];
        if (info == "") {
            info = "No Answer!";
        }
        cout << info << endl;
    }
    return 0;
}
