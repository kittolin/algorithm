/*
* 名称：打印极值点坐标

* 链接：http://985.so/ku4s
* 难度：简单
*/

#include <cstdio>

using namespace std;

int main() {
    int n, pre2, pre, cur;  // pre2, pre, cur 分别记录下标 i-2, i-1, i 的数值
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                scanf("%d", &pre2);
            } else if (i == 1) {
                scanf("%d", &pre);
                if (pre2 != pre) {
                    printf("%d ", 0);
                }
            } else {
                scanf("%d", &cur);  // cur 最小从 i=2 开始
                // pre > pre2 && pre > cur || pre < pre2 && pre < cur
                if ((pre - pre2) * (pre - cur) > 0) {
                    printf("%d ", i - 1);
                }
                pre2 = pre;
                pre = cur;
            }
        }
        if (pre2 != pre) {  // !!! 最后 pre 指向了最后一个元素
            printf("%d ", n - 1);
        }
        printf("\n");
    }
    return 0;
}
