/*
* 名称：连通分支数

* 链接：http://985.so/902w
* 难度：中等
*/

#include <cstdio>
#include <iostream>

using namespace std;

const int MAXN = 1e6;
int father[MAXN];
int height[MAXN];

int Find(int x) {
    if (x == father[x]) {
        return x;
    }
    father[x] = Find(father[x]);  // 路径压缩
    return father[x];
}

void Union(int x, int y) {
    x = Find(x);
    y = Find(y);
    if (x == y) {   // x 和 y 属于同一个集合(也包括一个节点的自环)，不用合并
        return;
    }
    if (height[x] > height[y]) {
        father[y] = x;
    } else if (height[x] < height[y]) {
        father[x] = y;
    } else {
        father[y] = x;
        height[x] ++;
    }
}

int main() {
    fill(father, father + MAXN, -1);  // 用 -1 表示该节点不存在
    int i, j;
    while (scanf("%d %d", &i, &j) != EOF) {
        if (father[i] == -1) {  // 如果节点是第一次输入，标记其为一个单独的集合，其父亲节点等于自身
            father[i] = i;
            height[i] = 0;
        }
        if (father[j] == -1) {
            father[j] = j;
            height[j] = 0;
        }
        Union(i, j);
    }

    int components = 0;
    for (int i = 0; i < MAXN; i++) {
        if (i == father[i]) {
            components ++;
        }
    }
    printf("%d\n", components);
    return 0;
}
