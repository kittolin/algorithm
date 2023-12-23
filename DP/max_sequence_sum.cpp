/*
* 名称：最大连续子序列和

* 链接：http://t.cn/AiYSlQMU
* 难度：中等
* 算法：固定一端，求以 Ai 为最后元素的最大连续子序列和
*      1 -2 3 4 -10 6
*      -    -       -
*      ---- ---
*           -------
*      状态转移方程：F(i) = max(Ai, F(i-1) + Ai)
*      边界：F(0) = A0
*/

#include <iostream>
#include <cstdio>
#include <climits>

using namespace std;

const int MAXN = 1e6 + 10;
const int INF = INT_MAX;

int nums[MAXN];
int memo[MAXN];
int dp[MAXN];

// 朴素递归
// 时间复杂度：O(n^2)
int MaxSeqSum1(int i) {
    if (i == 0) {
        return nums[0];
    }
    return max(nums[i], MaxSeqSum1(i - 1) + nums[i]);
}

// 递归 + 记忆法
// 时间复杂度：O(N)
int MaxSeqSum2(int i) {
    if (memo[i] != -1) {
        return memo[i];
    }

    if (i == 0) {
        memo[i] = nums[0];
    } else {
        memo[i] = max(nums[i], MaxSeqSum2(i - 1) + nums[i]);
    }
    return memo[i];
}

// 动态规划
// 时间复杂度：O(N)
int MaxSeqSum3(int n) {
    int maximum = -INF;
    for(int i = 0; i < n; i++) {
        if (i == 0) {
            dp[i] = nums[i];
        } else {
            dp[i] = max(nums[i], dp[i - 1] + nums[i]);
        }
        maximum = max(maximum, dp[i]);
    }
    return maximum;
}

int main() {
    int n;
    while(scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &nums[i]);
        }
        printf("%d\n", MaxSeqSum3(n));
    }

    return 0;
}
