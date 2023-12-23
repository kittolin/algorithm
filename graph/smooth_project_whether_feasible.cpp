/*
* 名称：畅通工程 - 是否可行并输出最低成本

* 链接：http://985.so/k0vf
* 难度：较难
* 算法：最小生成树 + 连通分支
*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXM = 100 + 10;
const int MAXN = 100 + 10;

struct Edge {
    int from;
    int to;
    int cost;
    Edge() {}
    bool operator<(const Edge& e) const {
        return cost < e.cost;
    }
};

int father[MAXM];
int height[MAXM];
Edge edges[MAXN];

void Initial(int m) {
    for (int i = 1; i <= m; i++) {
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

int Kruskal(int n) {
    sort(edges, edges + n);
    int cost = 0;
    for (int i = 0; i < n; i++) {
        int from = edges[i].from;
        int to = edges[i].to;
        if (Find(from) != Find(to)) {
            cost += edges[i].cost;
            Union(from, to);
        }
    }
    return cost;
}

bool Feasible(int m) {
    int component = 0;
    for (int i = 1; i <= m; i++) {
        if (i == father[i]) {
            component ++;
        }
    }
    return component == 1;  // 连通分支数等于 1 才是连通图
}

int main() {
    int n, m;   // n: 道路条数; m: 村庄数目
    while (scanf("%d %d", &n, &m) != EOF) {
        if (n == 0) {
            break;
        }
        Initial(m);
        for (int i = 0; i < n; i++) {
            scanf("%d %d %d", &edges[i].from, &edges[i].to, &edges[i].cost);
        }

        int leastCost = Kruskal(n); // !!! 只有执行 Kruskal 后才能执行 Feasible，不能颠倒
        if (Feasible(m)) {
            printf("%d\n", leastCost);
        } else {
            printf("?\n");
        }
    }
    return 0;
}
