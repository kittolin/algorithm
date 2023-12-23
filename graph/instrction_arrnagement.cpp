/*
* 名称：Instrction Arrangement

* 链接：http://acm.hdu.edu.cn/showproblem.php?pid=4109
* 分析：即求关键路径的汇点的最早开始时间
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <climits>

using namespace std;

const int MAXN = 1000 + 10;
const int INF = INT_MAX;

struct Edge {
    int to;
    int length;
    Edge(int t, int l): to(t), length(l) {}
};

vector<Edge> graph[MAXN];
int inDegree[MAXN];
int earliest[MAXN]; // 所有事件 V 的最早开始时间
int latest[MAXN];   // 所有事件 V 的最晚发生时间

int CriticalPath(int n) {
    int maxEarliest = 0;
    // 拓扑排序，求事件 V 的最早开始时间
    vector<int> topology;
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
            earliest[i] = 1;         // 所有入度为 0 的顶点的最早开始时间 Ve(Vi) = 1
        }
    }
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        maxEarliest = max(maxEarliest, earliest[v]); // 队列 q 存放的是入度为 0 的顶点，此时该顶点的最早开始时间已经算好的了 
        topology.push_back(v);
        for (int i = 0; i < graph[v].size(); i++) {
            int to = graph[v][i].to;
            int length = graph[v][i].length;
            inDegree[to] --;
            if (inDegree[to] == 0) {
                q.push(to);
            }
            earliest[to] = max(earliest[to], earliest[v] + length); // 计算所有后序事件的最早开始时间
        }
    }

    // 逆拓扑排序，求事件 V 的最晚发生时间
    for (int i = topology.size() - 1; i >= 0; i--) {
        int v = topology[i];
        if (graph[v].size() == 0) {
            // latest[v] = earliest[v];
            latest[v] = maxEarliest;    // 出度为 0 的顶点的最晚发生时间等于汇点的最早开始时间
        } else {
            latest[v] = INF;
        }
        for (int j = 0; j < graph[v].size(); j++) {
            int to = graph[v][j].to;
            int length = graph[v][j].length;
            latest[v] = min(latest[v], latest[to] - length);    // 计算当前事件的最晚发生时间
        }
    }
    return maxEarliest;
}

int main() {
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF) {
        memset(graph, 0, sizeof(graph));
        memset(earliest, 0, sizeof(earliest));
        memset(latest, 0, sizeof(latest));
        memset(inDegree, 0, sizeof(inDegree));
        while (m --) {
            int from, to, length;
            scanf("%d %d %d", &from, &to, &length);
            graph[from].push_back(Edge(to, length));
            inDegree[to] ++;
        }
        printf("%d\n", CriticalPath(n));
        for (int i = 0; i < n; i++) {
            printf("number: %d, early: %d, late: %d\n", i, earliest[i], latest[i]);
        }
    }
    return 0;
}
