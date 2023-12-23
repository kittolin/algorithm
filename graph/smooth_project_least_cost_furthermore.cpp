/*
* 名称：畅通工程 - 全省畅通还需的最低成本

* 链接：http://985.so/k0fk
* 难度：中等
* 算法：最小生成树，输入边时如果该边已创建，则合并该边对应的两顶点，再对未创建的边进行 Kruskal 算法
*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 100 + 10;

struct Edge {
    int from;
    int to;
    int cost;
    Edge() {}
    Edge(int f, int t, int c): from(f), to(t), cost(c) {}
    bool operator<(const Edge& e) const {
        return cost < e.cost;
    }
};

int father[MAXN];
int height[MAXN];
Edge edges[MAXN * MAXN];

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

int Kruskal(int edgeNum) {
    sort(edges, edges + edgeNum);
    int cost = 0;
    for (int i = 0; i < edgeNum; i++) {
        int from = edges[i].from;
        int to = edges[i].to;
        if (Find(from) != Find(to)) {
            cost += edges[i].cost;
            Union(from, to);
        }
    }
    return cost;
}

int main() {
    int n, from, to, cost, status;
    while (scanf("%d", &n) != EOF) {
        if (n == 0) {
            break;
        }
        Initial(n);

        int edgeNum = 0;
        for (int i = 0; i < n * (n - 1) / 2; i++) {
            scanf("%d %d %d %d", &from, &to, &cost, &status);
            if (status) {
                Union(from, to);
            } else {
                edges[edgeNum++] = Edge(from, to, cost);
            }
        }
        printf("%d\n", Kruskal(edgeNum));
    }
    return 0;
}
