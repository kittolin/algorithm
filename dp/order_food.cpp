/*
* 名称：点菜问题

* 链接：http://t.cn/AiYOrkXr
* 难度：中等
* 分析：每种菜只能点一次，01 背包问题
*/

#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 100 + 10;
const int MAXC = 1000 + 10;

int weights[MAXN];
int values[MAXN];
int dp1[MAXN][MAXC];
int dp2[MAXC];

// 空间复杂度：O(n * c)
int ZeroOnePack1(int n, int c) {
    for(int i = 0; i <= n; i++) {
        for (int j = 0; j <= c; j++) {
            if (i == 0 || j == 0) { // 不放任何东西或者背包容量为 0
                dp1[i][j] = 0;
                continue;           // !!!
            }
            if (j < weights[i]) {   // 背包容量小于第 i 件物品重量，就只能不放这件物品
                dp1[i][j] = dp1[i - 1][j];
            } else {
                dp1[i][j] = max(dp1[i - 1][j], dp1[i - 1][j - weights[i]] + values[i]);
            }
        }
    }
    return dp1[n][c];
}

// 空间复杂度：O(c)
int ZeroOnePack2(int n, int c) {
    // 还没开始放任何物品
    for (int j = 0; j <= c; j++) {
        dp2[j] = 0;
    }

    for(int i = 1; i <= n; i++) {
        for (int j = c; j >= weights[i]; j--) { // 从后往前更新
            dp2[j] = max(dp2[j], dp2[j - weights[i]] + values[i]);
        }
    }
    return dp2[c];
}

int main() {
    int c, n;
    while (scanf("%d %d", &c, &n) != EOF) {
        for (int i = 1; i <= n; i++) {
            scanf("%d %d", &weights[i], &values[i]);
        }
        printf("%d\n", ZeroOnePack2(n, c));
    }
    return 0;
}
