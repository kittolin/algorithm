/*
* 名称：还是畅通工程
* 来源：浙江大学复试上机题
* 链接：http://t.cn/AiWud0C6
* 难度：简单
* 算法：最小生成树
*/

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 100 + 10;

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
    // x，y 属于同一个集合，不用合并
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

struct Edge {
    int from;
    int to;
    int weight;
    bool operator<(const Edge& e) const {
        return weight < e.weight;   // 按权值从小到大排序
    }
};

Edge edges[MAXN * MAXN];

int Kruskal(int n) {
    int edgeNum = n * (n - 1) / 2;
    int ans = 0;
    sort(edges, edges + edgeNum);
    for (int i = 0; i < edgeNum; i++) {
        int from = edges[i].from;
        int to = edges[i].to;
        // 若两个顶点不属于同一个集合，则选中该边，并且合并这两个顶点
        if (Find(from) != Find(to)) {
            Union(from, to);
            ans += edges[i].weight;
        }
    }
    return ans;
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        if (n == 0) {
            break;
        }
        Initial(n);
        for (int i = 0; i < n * (n - 1) / 2; i++) {
            scanf("%d %d %d", &edges[i].from, &edges[i].to, &edges[i].weight);
        }
        printf("%d\n", Kruskal(n));
    }    
    return 0;
}
