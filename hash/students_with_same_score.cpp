/*
* 名称：统计同成绩学生人数

* 链接：http://985.so/km2m
* 难度：简单
*/

#include <cstdio>
#include <unordered_map>

using namespace std;

int main() {
    int n, score;
    while (scanf("%d", &n) != EOF) {
        if (n == 0) {
            break;
        }
        unordered_map<int, int> map;
        while (n --) {
            int tmp;
            scanf("%d", &tmp);
            map[tmp] ++;
        }
        scanf("%d", &score);
        printf("%d\n", map[score]);
    }
    return 0;
}
