/*
* 名称：二叉树

* 链接：http://t.cn/Ai0Ke6I0
* 难度：中等
*/

#include <iostream>
#include <cstdio>

using namespace std;

/*
*     i
*    / \
*  2i  2i+1
*/
int BinaryTreeNodesNum(int m, int n) {
    if (m > n) {
        return 0;
    }
    return 1 + BinaryTreeNodesNum(m * 2, n) + BinaryTreeNodesNum(m * 2 + 1, n);
}

int main() {
    int m, n;
    while (scanf("%d %d", &m, &n) != EOF) {
        if (m == 0 && n == 0) {
            break;
        }
        printf("%d\n", BinaryTreeNodesNum(m, n));
    }
    return 0;
}
