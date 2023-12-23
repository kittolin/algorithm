/*
* 名称：采购粮食支援灾区

* 链接：http://acm.hdu.edu.cn/showproblem.php?pid=2191
* 分析：资金总数对应于背包容量，每种大米有多袋，多重背包问题
*/

#include <iostream>
#include <cstdio>

using namespace std;

const int MAXM = 100 + 10;  // 大米种类上限
const int MAXN = 100 + 10;  // 资金上限
const int MAX_AMOUNT = 20;  // 每种大米袋数上限

struct rice {
    int price;              // 对应于物品重量
    int weight;             // 对应于物品价值
    int amount;
};

rice rices[MAXM];
int newPrices[MAXM * MAX_AMOUNT];  // 拆分后新的大米价格
int newWeights[MAXM * MAX_AMOUNT]; // 拆分后新的大米重量
int dp[MAXN];

int MultiPack(int m, int n) {
    int newM = 0;   // 拆分后新的大米种类数量
    for (int i = 0; i < m; i++) {
        // 对大米袋数进行指数拆分
        for (int j = 1; j <= rices[i].amount; j *= 2) {
            newM ++;
            newPrices[newM] = rices[i].price * j;
            newWeights[newM] = rices[i].weight * j;
            rices[i].amount -= j;
        }
        // 余量处理
        if (rices[i].amount > 0) {
            newM ++;
            newPrices[newM] = rices[i].price * rices[i].amount;
            newWeights[newM] = rices[i].weight * rices[i].amount;
        }
    }

    // 01 背包问题
    for (int j = 0; j <= n; j++) {
        dp[j] = 0;
    }
    for (int i = 1; i <= newM; i++) {
        for (int j = n; j >= newPrices[i]; j--) {
            dp[j] = max(dp[j], dp[j - newPrices[i]] + newWeights[i]);
        }
    }

    return dp[n];
}

int main() {
    int c, n, m;    // n: 资金总数，m：大米种类数量
    scanf("%d", &c);
    while (c --) {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < m; i++) {
            scanf("%d %d %d", &rices[i].price, &rices[i].weight, &rices[i].amount);
        }
        printf("%d\n", MultiPack(m, n));
    }
    return 0;
}
