/*
* 题目名称：N 阶楼梯上楼问题
* 题目来源：华中科技大学复试上机题
* 题目链接：http://t.cn/Aij9Fr3V
* 题目难度：较难
*/

#include <iostream>
#include <cstdio>
#include <string.h>

using namespace std;

const int MAXN = 90  + 10;
int memo[MAXN];
int dp[MAXN];

// 朴素递归
// 时间复杂度：O(2^N)
// 空间复杂度：O(N)
int NStairsWays1(int n) {
    if (n <= 2) {
        return n;
    }
    return NStairsWays1(n - 2) + NStairsWays1(n - 1);
}

// 递归 + 记忆法
// 时间复杂度：O(N)
// 空间复杂度：O(N)
int NStairsWays2(int n) {
    // 已经计算保存过的直接查表返回
    if (memo[n] != 0) {
        return memo[n];
    }

    if (n <= 2) {
        memo[n] = n;
        return n;
    }
    memo[n] = NStairsWays2(n - 2) + NStairsWays2(n - 1);
    return memo[n];
}

// 动态规划
// 时间复杂度：O(N)
// 空间复杂度：O(N)
void NStairsWays3() {
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i < MAXN; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
}

int main() {
    int n;
    // memset(dp, 0, sizeof(dp));
    NStairsWays3();

    while(scanf("%d", &n) != EOF) {
        printf("%d", dp[n]);
    }
    return 0;
}
