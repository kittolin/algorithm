/*
* 名称：畅通工程续-最短路径问题
* 来源：杭电 ACM
* 链接：ttp://acm.hdu.edu.cn/showproblem.php?pid=1874
* 算法：Dijkstra
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
#include <climits>

using namespace std;

const int MAXN = 200 + 10;
const int INF = INT_MAX;

struct Edge {
    int to;
    int distance;
    Edge(int t, int d): to(t), distance(d) {}
};

struct Vertex {
    int number;   // 顶点的编号
    int distance; // 源点到该顶点的最短距离
    Vertex(int n, int d): number(n), distance(d) {}
    bool operator<(const Vertex& v) const {
        return distance > v.distance;   // 距离越小的优先级越高
    }
};

vector<Edge> graph[MAXN]; // 数组的下标表示 from
int minDis[MAXN];    // 源点到各个顶点的最短距离
bool visited[MAXN];       // 标记顶点是否已访问过

void Dijkstra(int n, int start) {
    memset(visited, false, sizeof(visited));
    // memset(minDis, INF, sizeof(minDis));
    fill(minDis, minDis + n, INF);
    minDis[start] = 0;

    for (int i = 0; i < n; i++) {
        // 找到当前未访问顶点中 minD 值最小的顶点
        int v = -1; // !!! v 初值不能设置为 0，因为 0 号元素可能已经 visited 过了
        for (int j = 0; j < n; j++) {
            if (visited[j]) {
                continue;
            }
            if (v == - 1 || minDis[j] < minDis[v]) {
                v = j;
            }
        }

        // 更新 v 指向的所有未访问顶点的 minD 值
        for (int j = 0; j < graph[v].size(); j++) {
            int to = graph[v][j].to;
            int d = graph[v][j].distance;
            if (!visited[to] && minDis[v] + d < minDis[to]) {
                minDis[to] = minDis[v] + d;
            }
        }
        visited[v] = true;
    }
}

void DijkstraHeap(int n, int start) {
    // memset(minDis, INF, sizeof(minDis));
    fill(minDis, minDis + n, INF); // 不能用 memset
    minDis[start] = 0;
    priority_queue<Vertex> pq;     // 优先队列存放未访问的顶点，故不用 visited 数组了
    pq.push(Vertex(start, 0));

    while (!pq.empty()) {
        int v = pq.top().number;
        pq.pop();
        for (int j = 0; j < graph[v].size(); j++) {
            int to = graph[v][j].to;
            int d = graph[v][j].distance;
            if (minDis[v] + d < minDis[to]) {
                minDis[to] = minDis[v] + d;
                // 因为一开始除源点外其他所有顶点都为 INF，所以最终所有连通的顶点都会更新到 minD 值，并进入优先队列；
                // 而且可能会 push 进编号重复的顶点，但不影响结果
                pq.push(Vertex(to, minDis[to]));
            }
        }
    }
}

int main() {
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF) {
        memset(graph, 0, sizeof(graph));
        while (m --) {
            int from, to, distance;
            scanf("%d %d %d", &from, &to, &distance);
            graph[from].push_back(Edge(to, distance));
            graph[to].push_back(Edge(from, distance)); // 无向边
        }
        int start, end;
        scanf("%d %d", &start, &end);

        DijkstraHeap(n, start);
        if (minDis[end] == INF) {  // 终点不可达
            minDis[end] = -1;
        }
        printf("%d\n", minDis[end]);
    }
    return 0;
}
