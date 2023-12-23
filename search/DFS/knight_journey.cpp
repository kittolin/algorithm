/*
* 名称：A Knight's Journey

* 链接：http://poj.org/problem?id=2488
* 
* 算法：DFS
*      (1)状态空间：(x, y, step)
*      (2)状态转移：(x+2, y+1, step+1), (x+1, y+2, step+1), ......
*      (3)起始状态：(0, 0, 1)
*      (4)目标状态：(x, y, size of board)
*
* 搜索树：
*           (0,0,1)      
*             / \
*       (2,1,2) (1,2,2) ......
*         / \
*   (4,2,3) (3,2,3) ......
*/

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

const int MAXN = 30;
bool visited[MAXN][MAXN];  // 最终是根据 step 是否等于棋盘大小来判断目标状态的，所以要保证每个格子只走一次
int p, q;  // 定义成全局变量，避免每次 DFS 递归都需要传入
int direction[8][2] = {
    {-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}
};  // 要保证 path 的字典序，所以顺序不能颠倒

struct Status {
    int x;
    int y;
    int step;
    Status(int x, int y, int step): x(x), y(y), step(step) {}
};

bool valid(Status s) {
    return s.x >= 0 && s.x < q && s.y >= 0 && s.y < p && !visited[s.x][s.y];
}

bool DFS(Status s, string path) {
    // 查找到目标状态
    if (s.step == p * q) {
        cout << path << endl << endl;
        return true;
    }

    for (int i = 0; i < 8; i++) {
        Status ns = Status(s.x + direction[i][0], s.y + direction[i][1], s.step + 1);
        if (!valid(ns)) {
            continue;
        }

        visited[ns.x][ns.y] = true;  // 标记该位置已访问，防止后续 DFS 重复访问
        char row = ns.y + '1';
        char col = ns.x + 'A';
        // 只要找到一条满足条件的 path 就可以返回了
        if (DFS(ns, path + col + row)) {
            return true;
        }
        visited[ns.x][ns.y] = false;  // 从当前位置出发未能找到正确路径，取消该标记
    }
    return false;
}

int main() {
    int n;
    scanf("%d", &n);
    int count = 0;
    while (n --) {
        scanf("%d %d", &p, &q);
        memset(visited, false, sizeof(visited));
        cout << "Scenario #" << ++count << ":" << endl;

        visited[0][0] = true;
        if (!DFS(Status(0, 0, 1), "A1")) {
            cout << "impossible" << endl << endl;
        }
    }
    return 0;
}
