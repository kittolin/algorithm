/*
* 名称：最长递增子序列
* 来源：北京大学 poj
* 链接：http://poj.org/problem?id=2533
*
* 算法：固定一端，求以 Ai 为最后元素的最长递增子序列
*      3 7 1 2 5
*      -
*      ---
*          -
*          ---
*          -----
*
*     状态转移方程：F(i) = Max(F(j)) + 1, j < i && Aj < Ai
*     边界：F(0) = 1
*/

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1000 + 10;
int nums[MAXN];
int memo[MAXN];
int dp[MAXN];

// 朴素递归
// 时间复杂度：O(2^n)
int LongestOrderedSeq1(int i) {
    if (i == 0) {
        return 1;
    }

    int maximum = 1;
    for(int j = 0; j < i; j++) {
        // 注意是 < , 不是 <=
        if (nums[j] < nums[i]) {
            maximum = max(maximum, LongestOrderedSeq1(j) + 1);
        }
    }
    return maximum;
}

// 递归 + 记忆法
// 时间复杂度：O(n^2)
int LongestOrderedSeq2(int i) {
    if (memo[i] != 0) {
        return memo[i];
    }

    int temp = 1;
    if (i != 0) {
        for(int j = 0; j < i; j++) {
            if (nums[j] < nums[i]) {
                temp = max(temp, LongestOrderedSeq2(j) + 1);
            }
        }
    }
    memo[i] = temp;
    return temp;
}

// 动态规划
// 时间复杂度：O(n^2)
int LongestOrderedSeq3(int n) {
    int maximum = 0;
    for(int i = 0; i < n; i++) {
        if (i == 0) {
            dp[i] = 1;
        } else {
            int temp = 1;
            for(int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    temp = max(temp, dp[j] + 1);
                }
            }
            dp[i] = temp;
        }

        maximum = max(maximum, dp[i]);
    }
    return maximum;
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    printf("%d", LongestOrderedSeq3(n));
    return 0;
}
