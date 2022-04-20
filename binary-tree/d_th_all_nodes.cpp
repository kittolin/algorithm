/*
* 名称：完全二叉树第 d 层所有节点
* 来源：北京邮电大学复试上机题
* 链接：http://985.so/9ntg
* 难度：较难
*/

#include <cstdio>
#include <cmath>

using namespace std;

const int MAXN = 1000 + 10;
int nodes[MAXN];

void DthDepthAllNodes(int n, int depth) {
    int first = pow(2, depth - 1);  // 第 d 层第一个节点下标，2 ^ (d - 1) - 1 + 1
    int number = first;             // 第 d 层节点个数，2 ^ (d - 1)
    if (first > n) {
        printf("EMPTY\n");
        return;
    }
    for (int i = first; i <= n && i < first + number; i++) { // 要考虑到第 d 层满节点和不满的两种情况
        if (i == first) {
            printf("%d", nodes[i]);
        } else {
            printf(" %d", nodes[i]);
        }
    }
    printf("\n");
}

int main() {
    int n, d;
    while (scanf("%d", &n) != EOF) {
        for (int i = 1; i <= n; i++) {  // 完全二叉树通常从 1 开始存放
            scanf("%d", &nodes[i]);
        }
        scanf("%d", &d);
        DthDepthAllNodes(n, d);
    }
    return 0;
}
