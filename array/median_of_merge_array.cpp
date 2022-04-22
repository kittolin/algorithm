/*
* 名称：取中值
* 来源：上海交通大学复试上机题
* 链接：http://985.so/903t
* 难度：较难
*/

#include <cstdio>

using namespace std;

const int MAXN = 1e6 + 10;

int front[MAXN];
int behind[MAXN];

int main() {
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF) {
        for (int i = 1; i <= n; i++) {  // 从下标 1 开始存放
            scanf("%d", &front[i]);
        }
        for (int i = 1; i <= m; i++) {
            scanf("%d", &behind[i]);
        }
        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b, &c, &d);

        int median = ((b - a + 1) + (d - c + 1) + 1) / 2; // 合并后的数组中间位置的下标（从 1 开始）
        if (median - 1 <= b - a) { // 在前面数组中
            printf("%d\n", front[median - 1 + a]);
        } else {                   // 在后面数组中
            printf("%d\n", behind[median - 1 + a - b + c - 1]);
        }
    }
    return 0;
}
