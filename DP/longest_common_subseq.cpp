/*
* 名称：最长公共子序列
* 来源：杭电 acm
* 链接：https://acm.hdu.edu.cn/showproblem.php?pid=1159
*
* 算法：两序列都固定一端，求以 Ai，Bj 为最后元素的的最长公共子序列
*      A1 A2 ... Ai     Bi B2 ... Bj
*      状态转移方程：F(i, j) = F(i-1, j-1) + 1,           Ai = Bj
*                 F(i, j) = Max(F(i, j-1), F(i-1, j))   Ai ≠ Bj
*      边界：F(0, x) = F(x, 0) = 0
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1000 + 10;
char str1[MAXN];
char str2[MAXN];
int memo[MAXN][MAXN];
int dp[MAXN][MAXN];

// 朴素递归
// 时间复杂度：O(2^(n+m))
int CommonSubSeq1(int i, int j) {
    if (i == 0 || j == 0) {
        return 0;
    }

    int ans;
    if (str1[i] == str2[j]) {
        ans = CommonSubSeq1(i - 1, j - 1) + 1;
    } else {
        ans = max(CommonSubSeq1(i, j - 1), CommonSubSeq1(i - 1, j));
    }
    return ans;
}

// 递归 + 记忆法
// 时间复杂度：O(n * m)
int CommonSubSeq2(int i, int j) {
    if (memo[i][j] != -1) {
        return memo[i][j];
    }

    int ans;
    if (i == 0 || j == 0) {
        ans = 0;
    } else if (str1[i] == str2[j]) {
        ans = CommonSubSeq2(i - 1, j - 1) + 1;
    } else {
        ans = max(CommonSubSeq2(i, j - 1), CommonSubSeq2(i - 1, j));
    }
    memo[i][j] = ans;
    return ans;
}

// 动态规划
// 时间复杂度：O(n * m)
int CommonSubSeq3(int n, int m) {
    for (int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            if (i == 0 || j== 0) {
                dp[i][j] = 0;
            } else if (str1[i] == str2[j]) {
                dp[i][j] = dp[i - 1][j - 1] +1;
            } else {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    return dp[n][m];
}

int main() {
    while(scanf("%s %s", str1 + 1, str2 + 1) != EOF) {
        int n = strlen(str1 + 1);
        int m = strlen(str2 + 1);
        // for(int i = 0; i <= n; i++) {
        //     for(int j = 0; j <= m; j++) {
        //         memo[i][j] = -1;
        //     }
        // }
        printf("%d\n", CommonSubSeq3(n, m));
    }
    return 0;
}
