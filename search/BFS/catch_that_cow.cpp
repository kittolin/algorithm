/*
* 名称：Catch That Cow
* 来源：北京大学 POJ
* 链接：http://poj.org/problem?id=3278
*
* 算法：BFS
*      (1)状态空间：(位置 p, 时间 t)
*      (2)状态转移：(p-1, t+1), (p+1, t+1), (p*2, t+1)
*      (3)起始状态：(n, 0)
*      (4)目标状态：(k, lowest time)
*
* 搜索树：
*                      (n, 0)
*                    /   |    \
*            (n-1, 1) (n+1,1) (2*n, 1)
*           /   |   \
*   (n-2, 2) (n, 2) (2*(n-1), 2) ......
*/

#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

const int MAXN = 1e5 + 10;
bool visited[MAXN]; // 防止重复访问，例如：(1, 1) -> (2, 2) -> (1, 3)，(1, 3) 为无效状态

struct Status {
    int pos;
    int time;
    Status(int p, int t): pos(p), time(t) {}
};

bool valid(Status s) {
    return s.pos >= 0 && s.pos < MAXN && !visited[s.pos];
}

int BFS(int n, int k) {
    queue<Status> q;
    q.push(Status(n, 0));   // 压入起始状态
    visited[n] = true;      // 标记起点已放入队列

    while (!q.empty()) {
        Status cur = q.front();
        q.pop();
        if (cur.pos == k) { // 查找成功
            return cur.time;
        }
        /*
        * !!! 在队列取出后再标记，会导致代码超时，例如：
        *
        *                                  (2, 0)
        *                 /                  |    \
        *           (1, 1)                (3, 1)  (4, 1)
        *         /   |   \             /   |   \
        *   (0, 2) (2, 2) (2, 2)  (2, 2) (4, 2) (6, 2)
        *
        * 在队列取出 (3, 1) 访问后，会导致重复放入 (4, 2)
        * queue: (4, 1), (0, 2), (4, 2), (6, 2)
        * visited: 1, 2, 3
        */
        // visited[cur.pos] = true;

        // 压入新的三个状态
        for (int i = 0; i < 3; i++) {
            Status next = cur;
            if (i == 0) {
                next.pos --;
            } else if (i == 1) {
                next.pos ++;
            } else {
                next.pos *= 2;
            }
            next.time ++;
            if (valid(next)) {
                q.push(next);
                visited[next.pos] = true;   // 标记该点已放入队列
            }
        }
    }
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    memset(visited, false, sizeof(visited));
    printf("%d\n", BFS(n, k));
    return 0;
}
