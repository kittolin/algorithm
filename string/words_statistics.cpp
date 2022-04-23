/*
* 名称：统计单词
* 来源：华中科技大学复试上机题
* 链接：http://985.so/96r5
* 难度：较难
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
    string text;
    while (getline(cin, text)) {
        int count = 0;
        for (int i = 0; i < text.size() - 1; i++) {
            if (text[i] == ' ') {
                if (count > 0) {    // 避免有多个连着的空格时重复输出
                    printf("%d ", count);
                }
                count = 0;
            } else {
                count ++;
            }
        }
        if (count > 0) {
            printf("%d", count);
        }
        printf("\n");
    }
    return 0;
}
