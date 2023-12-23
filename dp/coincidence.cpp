/*
* 名称：Coincidence

* 链接：http://985.so/90gx
* 难度：简单
* 分析：求最长公共子序列长度，动态规划
*/

#include <iostream>
#include <string>

using namespace std;

const int MAXN = 100 + 10;

int dp[MAXN][MAXN];
string str1, str2;

int LongestCommonSubSeq(int n, int m) {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
                continue;
            }
            if (str1[i] == str2[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][m];
}

int main() {
    while (cin >> str1 >> str2) {
        str1 = " " + str1;  // 使得有效字符从 1 开始
        str2 = " " + str2;
        cout << LongestCommonSubSeq(str1.size() - 1, str2.size() - 1);
    }
    return 0;
}
