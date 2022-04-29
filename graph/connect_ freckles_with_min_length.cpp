/*
* 名称：Freckles
* 来源：北京大学复试上机题
* 链接：http://985.so/k5xu
* 难度：简单
* 算法：最小生成树问题，Kruskal Algorithm
*/

#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAXN = 100 + 10;

struct Vertex {
    double x;
    double y;
};

struct Edge {
    int from;
    int to;
    double distance;
    Edge() {}   // edges 数组初始化时会用到
    Edge(int f, int t, double d): from(f), to(t), distance(d) {}
    bool operator<(const Edge& e) const {
        return distance < e.distance;
    };
};

int father[MAXN];
int height[MAXN];
Vertex vs[MAXN];  // 数组下标表示顶点编号
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

double Kruskal(int n) {
    sort(edges, edges + n * (n - 1) / 2);
    double ans = 0;
    for (int i = 0; i < n * (n - 1) / 2; i++) {
        int from = edges[i].from;
        int to = edges[i].to;
        if (Find(from) != Find(to)) {
            ans += edges[i].distance;
            Union(from, to);
        }
    }
    return ans;
}

int main() {
    int n;
    scanf("%d", &n);
    Initial(n);

    int edgesNum = 0;
    double distance;
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &vs[i].x, &vs[i].y);
        for (int j = 0; j < i; j++) {
            distance = sqrt((vs[i].x - vs[j].x) * (vs[i].x - vs[j].x) + (vs[i].y - vs[j].y) * (vs[i].y - vs[j].y));
            edges[edgesNum++] = Edge(i, j, distance);
        }
    }
    printf("%.2f\n", Kruskal(n));
    return 0;
}
