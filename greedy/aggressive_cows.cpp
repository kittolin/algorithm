/*
* 名称：Aggressive Cows

* 链接：http://poj.org/problem?id=2456
* 算法：最大的最小间距，采用二分策略，转化为判定性问题
*      (1)判断间距 d 是否可行
*      (2)对间距 d 采取二分策略
*/

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1e5 + 10;
int stalls[MAXN];

// 将 c 头牛放到 n 个棚，判断以 d 作为最小间距是否可行
bool Judge(int n, int c, int d) {
    int cur = stalls[0];
    int num = 1;
    for (int i = 1; i < n; i++) {
        // 两个棚之间若满足最小间距 d，就放入一头新的牛
        if (stalls[i] - cur >= d) {
            cur = stalls[i];
            num ++;
        }
        if (num >= c) {
            return true;
        }
    }
    return false;
}

int main() {
    int n, c;
    scanf("%d%d",&n, &c);
    for(int i = 0; i < n; i++) {
        scanf("%d", &stalls[i]);
    }
    sort(stalls, stalls + n);

    int min = 1, max = stalls[n - 1] - stalls[0];  // 两头牛不能放到同一个棚里，最小间距为 1
    while (min <= max) {
        int mid = min + (max - min) / 2;
        if (Judge(n, c, mid)) {
            min = mid + 1;
        } else {
            max = mid - 1;
        }
    }
    printf("%d", max);
    return 0;
}
