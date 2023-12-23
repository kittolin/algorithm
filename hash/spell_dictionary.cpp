/*
* 名称：魔咒词典

* 链接：http://985.so/k16x
* 难度：中等
*/


#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    string item, spell, function;
    unordered_map<string, string> map;
    while (getline(cin, item)) {
        if (item == "@END@") {
            break;
        }
        spell = item.substr(0, item.find("]") + 1);
        function = item.substr(item.find("]") + 2);
        map[spell] = function;
        map[function] = spell.substr(1, spell.size() - 2);  // spell 去掉左右中括号 []
    }

    int n;
    cin >> n;
    getchar();  // !!! 吃掉回车
    string testCase;
    while (n --) {
        getline(cin, testCase);
        if (map[testCase] == "") {
            cout << "what?" << endl;
        } else {
            cout << map[testCase] << endl;
        }
    }
    return 0;
}
