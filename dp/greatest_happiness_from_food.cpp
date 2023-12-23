/*
* 名称：从食物中获取最大幸福值

* 链接：https://acm.hdu.edu.cn/showproblem.php?pid=4508
* 分析：没有限制每种食物的数量，完全背包问题
* 注意：C++ 识别不了 max，要用 G++
*/

#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 100 + 10;
const int MAXM = 1e5 + 10;

int weights[MAXN];
int values[MAXN];
int dp1[MAXN][MAXM];
int dp2[MAXM];

// 空间复杂度：O(n * m)
int CompletePack1(int n, int m) {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 || j == 0) {  // 不放任何东西或者背包容量为 0
                dp1[i][j] = 0;
                continue;            // !!!
            }
            if (j < weights[i]) {   // 背包容量小于第 i 件物品重量，就只能不放这件物品
                dp1[i][j] = dp1[i - 1][j];
            } else {
                dp1[i][j] = max(dp1[i - 1][j], dp1[i][j - weights[i]] + values[i]);
            }
        }
    }
    return dp1[n][m];
}

// 空间复杂度：O(m)
int CompletePack2(int n, int m) {
    // 还没开始放任何物品
    for (int j = 0; j <= m; j++) {
        dp2[j] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = weights[i]; j <= m; j++) {     // 从前往后更新
            dp2[j] = max(dp2[j], dp2[j - weights[i]] + values[i]);
        }
    }
    return dp2[m];
}

int main() {
    int n, m;
    while (scanf("%d", &n) != EOF) {
        for (int i = 1; i <= n; i++) {
            scanf("%d %d", &values[i], &weights[i]);
        }
        scanf("%d", &m);
        printf("%d\n", CompletePack2(n, m));
    }
    return 0;
}
