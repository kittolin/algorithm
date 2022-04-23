/*
* 名称：找重复的字符的位置
* 来源：华中科技大学复试上机题
* 链接：http://985.so/96m4
* 难度：较难
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    string str;
    while (cin >> str) {
        unordered_map<char, vector<int> > map;
        // 先统计每个字符出现的索引位置
        for (int i = 0; i < str.size(); i++) {
            map[str[i]].push_back(i);
        }

        for (int i = 0; i < str.size(); i++) {
            vector<int> indexes = map[str[i]];
            if (indexes.size() <= 1) {
                continue;
            }

            for (int j = 0; j < indexes.size(); j++) {
                if (j == 0) {
                    printf("%c:%d", str[i], indexes[j]);
                } else {
                    printf(",%c:%d", str[i], indexes[j]);
                }
            }
            printf("\n");
            map.erase(str[i]);  // 清掉该字符 key，避免重复打印
        }
    }
    return 0;
}
