/*
* 名称：哈夫曼树

* 链接：http://t.cn/AiCuGMki
* 难度：中等
* 算法：
*            19
*           / \
*         10   9
*        / \
*       5   5
*      / \
*     3   2
*    / \
*   1   2
*
*  最小权值的两种算法：
* (1) 1 * 4 + 2 * 4 + 2 * 3 + 5 * 2 + 9 * 1 = 37
* (2) 3 + 5 + 10 + 19 = 37
*/

#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        priority_queue<int, vector<int>, greater<int> > pq; // 数越小的优先级越高
        while (n --) {
            int i;
            scanf("%d", &i);
            pq.push(i);
        }

        int weight = 0;
        // 当优先队列只剩一个数时，表明计算结束
        while (pq.size() > 1) {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();

            weight += (a + b);
            pq.push(a + b);
        }
        printf("%d\n", weight);
    }
    return 0;
}
