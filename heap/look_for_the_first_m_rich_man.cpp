/*
* 名称：寻找大富翁
* 来源：浙江大学复试上机题
* 链接：http://985.so/k177
* 难度：中等
*/

#include <cstdio>
#include <queue>

using namespace std;

const int MAXM = 15;
int buf[MAXM];

int main() {
    int n, m, money;
    while (scanf("%d %d", &n, &m) != EOF) {
        if (n == 0 && m == 0) {
            break;
        }

        priority_queue<int, vector<int>, greater<int> > pq; // 最小堆
        while (n --) {
            scanf("%d", &money);
            if (pq.size() < m) {             // 先放满 m 个数
                pq.push(money);
            } else if (money > pq.front()) { // 新元素大于堆顶元素的，弹出堆顶元素，放入新元素 
                pq.pop();
                pq.push(money);
            }
        }

        // 逆序输出
        int size = pq.size();
        for (int i = size - 1; i >= 0; i--) {
            buf[i] = pq.front();
            pq.pop();
        }
        for (int i = 0; i < size; i++) {
            printf("%d ", buf[i]);
        }
    }
    return 0;
}
