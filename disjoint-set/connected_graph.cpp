/*
* 名称：连通图
* 来源：吉林大学复试上机题
* 链接：http://t.cn/AiO77VoA
* 难度：中等
* 算法：利用并查集，对有边相连的节点进行合并，求出连通分量。连通分量等于 1 的为连通图，大于 1 的为非连通图。
*/

#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 1000 + 10;

int father[MAXN];
int height[MAXN];

void Initial(int n) {
    for (int i = 1; i <= n; i++) {
        father[i] = i;
        height[i] = 0;
    }
}

int Find(int x) {
    if (x == father[x]) {
        return x;
    }
    father[x] = Find(father[x]);
    return father[x];
}

void Union(int x, int y) {
    x = Find(x);
    y = Find(y);
    if (x == y) {
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
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF) {
        if (n == 0) {
            break;
        }

        Initial(n);
        for (int i = 0; i < m; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            Union(x, y);
        }

        int component = 0;
        for (int i = 1; i <= n; i++) {
            // 有多少树根，就是有多少连通分量
            if (i == father[i]) {
                component ++;
            }
        }

        if (component == 1) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}
