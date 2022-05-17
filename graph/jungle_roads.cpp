/*
* 名称：Jungle Roads
* 来源：北京大学复试上机题
* 链接：http://985.so/a9em
* 难度：中等
* 算法：最小生成树，Kruskal
* 注意：用 scanf("%c %d") 同时输入字符和整数时会出现奇奇怪怪的 bug。。。
*/

#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 30;

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
    for (int i = 0; i < n; i++) {
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

int Kruskal(int m) {
    sort(edges, edges + m);
    int result = 0;
    for (int i = 0; i < m; i++) {
        if (Find(edges[i].from) != Find(edges[i].to)) {
            Union(edges[i].from, edges[i].to);
            result += edges[i].cost;
        }
    }
    return result;
}

int main() {
    int n, roads, cost;
    char from, to;
    while (cin >> n) {
        if (n == 0) {
            break;
        }

        Initial(n);
        int edgeNum = 0;
        for (int i = 0; i < n - 1; i++) {
            cin >> from >> roads;
            while (roads --) {
                cin >> to >> cost;
                edges[edgeNum++] = Edge(from - 'A', to - 'A', cost);
            }
        }
        cout << Kruskal(edgeNum) << endl;
    }
    return 0;
}
