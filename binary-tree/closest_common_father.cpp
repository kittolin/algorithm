/*
* 名称：完全二叉树两节点最近的公共父节点

* 链接：http://985.so/kscm
* 难度：中等
*/

#include <cstdio>

using namespace std;

// 两节点中较大的节点向上浮，循环进行
int CommonFather(int x, int y) {
    // while (1) {
    //     if (x > y) {
    //         x /= 2;
    //     } else if (x < y) {
    //         y /= 2;
    //     } else {
    //         return x;
    //     }
    // }
    while (x != y) {
        x > y? x /= 2: y /= 2;
    }
    return x;
}

int main() {
    int x, y;
    while (scanf("%d %d", &x, &y) != EOF) {
        printf("%d\n", CommonFather(x, y));
    }
    return 0;
}
