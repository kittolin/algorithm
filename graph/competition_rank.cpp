/*
* 名称：确定比赛名次
* 来源：杭电 ACM
* 链接：http://acm.hdu.edu.cn/showproblem.php?pid=1285
* 算法：拓扑排序
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

const int MAXN = 500 + 10;

vector<int> graph[MAXN];
int inDegree[MAXN]; // 每个顶点的入度

vector<int> TopologicalSort(int n) {
    vector<int> topology;
    priority_queue<int, vector<int>, greater<int> > pq; // 越小的优先级越高

    // 将所有入度为 0 的顶点放入优先队列
    for (int i = 1; i <= n; i++) {
        if (inDegree[i] == 0) {
            pq.push(i);
        }
    }

    while (!pq.empty()) {
        int u = pq.top();
        pq.pop();
        topology.push_back(u);
        // 将顶点 u 的所有出边删除，即出边指向的顶点的入度减 1
        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i];
            inDegree[v] --;
            if (inDegree[v] == 0) {
                pq.push(v);
            }
        }
    }
    return topology;
}

int main() {
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF) {
        memset(graph, 0, sizeof(graph));    // !!! 不清空会影响后续的测试用例
        memset(inDegree, 0, sizeof(inDegree));
        while (m --) {
            int from, to;
            scanf("%d %d", &from, &to);
            graph[from].push_back(to);
            inDegree[to] ++;
        }
        vector<int> v = TopologicalSort(n);
        for (int i = 0; i < v.size(); i++) {
            if (i == 0) {
                printf("%d", v[i]);
            } else {
                printf(" %d", v[i]);
            }
        }
        printf("\n");
    }
    return 0;
}
