/*
* 名称：Square
* 来源：北京大学 POJ
* 链接：http://poj.org/problem?id=2362
* 减枝：(1)木棍累和不能被 4 整除
*      (2)有木棍长度大于边长 side(需排序)
*      (3)记录失败的长度，避免重复匹配(需排序)
*      (4)无需每次从头开始匹配木棍(需排序)，匹配 1+2+3 和 1+3+2 是一样的
*
* 算法：DFS，需要减枝优化，否则会超时
*      (1)状态空间：(当前木棍累和 sum，当前匹配成功的边数 number，下次开始匹配的位置 pos)
*      (2)状态转移：(sum+s[i], number, pos+1) -> (0, number+1. 0)
*      (3)起始状态：(0, 0, 0)
*      (4)目标状态：(0，3, pos)
*
* 搜索树：
*                        (0, 0, 0)
*                          / \
*               (s[0], 0, 1) (s[1], 0, 2) ......
*                   / \
*   (s[0]+s[1], 0, 2) (s[0]+s[2], 0, 3) ......
*/

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXM = 24;
int sticks[MAXM];
bool visited[MAXM];
int m, side;

struct Status {
    int sum;
    int number;
    int pos;
    Status(int sum, int num, int pos): sum(sum), number(num), pos(pos) {}
};

bool DFS(Status s) {
    // 匹配成功 3 条边即可，剩余的木棍肯定能组成第 4 条边
    if (s.number == 3) {
        return true;
    }

    int sample = 0;
    for (int i = s.pos; i < m; i++) {
        if (visited[i] || s.sum + sticks[i] > side || sticks[i] == sample) { // 无效状态，跳过
            continue;
        }
        Status ns = Status(s.sum + sticks[i], s.number, i + 1);              // 下层递归从 i+1 位置开始匹配
        if (ns.sum == side) {
            ns.sum = 0;
            ns.number ++;
            ns.pos = 0;
        }

        visited[i] = true;      //标记该木棍已使用，防止后续 DFS 重复使用
        if (DFS(ns)) {          // 只要找到一种构成方式就返回
            return true;
        } else {
            sample = sticks[i]; // 记录失败的长度，避免重复匹配
        }
        visited[i] = false;     // !!! 该构成方式不可行，取消标记
    }
    return false;
}

int main() {
    int n;
    scanf("%d", &n);
    while (n --) {
        scanf("%d", &m);
        int len = 0;
        for (int i = 0; i < m; i++) {
            scanf("%d", &sticks[i]);
            len += sticks[i];
        }

        // 木棍累和不能被 4 整除，减枝
        if (len % 4 != 0) {  
            printf("no\n");
            continue;
        }

        side = len / 4;
        sort(sticks, sticks + m);
        // 有木棍长度大于边长 side，减枝
        if (sticks[m - 1] > side) {
            printf("no\n");
            continue;
        }

        memset(visited, false, sizeof(visited));
        if (DFS(Status(0, 0, 0))) {
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }
    return 0;
}
