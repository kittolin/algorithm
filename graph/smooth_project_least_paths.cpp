/*
* 名称：畅通工程
* 来源：浙江大学复试上机题
* 链接：http://985.so/km1h
* 难度：简单
* 算法：生成树，最少还需建设多少道路，即求连通分支数 - 1
*/

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
    father[x] = Find(father[x]);    // 路径压缩
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
    while (scanf("%d", &n) != EOF) {
        if (n == 0) {
            break;
        }
        scanf("%d", &m);
        if (m == 0) {
            printf("%d\n", n - 1);
            continue;
        }

        Initial(n);
        while (m --) {
            int x, y;
            scanf("%d %d", &x, &y);
            Union(x, y);
        }
        int components = 0;
        for (int i = 1; i <= n; i++) {
            if (i == father[i]) {
                components ++;
            }
        }
        printf("%d\n", components - 1);
    }
    return 0;
}
