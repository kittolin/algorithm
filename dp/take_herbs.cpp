/*
* 名称：采药

* 链接：http://985.so/amb2
* 难度：中等
* 算法：01 背包问题
*/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXM = 100 + 10;
const int MAXT = 1000 + 10;

int cost[MAXM];   // 采每株药的时间
int value[MAXM];  // 每株草药的价值
int dp[MAXT];

int MaxSumValue(int m, int t) {
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= m; i++) {
        for (int j = t; j >= cost[i]; j--) {
            dp[j] = max(dp[j], dp[j - cost[i]] + value[i]);
        }
    }
    return dp[t];
} 

int main() {
    int t, m;
    while (scanf("%d %d", &t, &m) != EOF) {
        for (int i = 1; i <= m; i++) {
            scanf("%d", &cost[i]);
            scanf("%d", &value[i]);
        }
        printf("%d\n", MaxSumValue(m, t));
    }
    return 0;
}
