/*
* 名称：找最小数

* 链接：http://985.so/9n8w
* 难度：简单
*/

#include <cstdio>

using namespace std;

int main() {
    int n, x, y, minX, minY;
    while (scanf("%d", &n) != EOF) {
        scanf("%d %d", &minX, &minY);
        for (int i = 1; i < n; i++) {
            scanf("%d %d", &x, &y);
            if (x < minX) {
                minX = x;
                minY = y;
            }
            if (x == minX && y < minY) {
                minY = y;
            }
        }
        printf("%d %d\n", minX, minY);
    }
}
