/*
* 名称：Fibonacci
* 来源：上海交通大学复试上机题
* 链接：http://t.cn/Ai0K3tU5
* 难度：简单
*/

#include <iostream>
#include <cstdio>

using namespace std;
const int MAXN = 30 + 10;
int dp[MAXN];

// 分治法
// 时间复杂度：O(2^n)
int DivideConquer(int n) {
    if (n == 0 || n == 1) {
        return n;
    }
    return DivideConquer(n - 1) + DivideConquer(n - 2);
}

// 递推法
// 时间复杂度：O(n)
void Initial() {
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2; i < MAXN; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
}

// 矩阵快速幂 TODO
// 时间复杂度：O(log n)

int main() {
    Initial();
    int n;
    while (scanf("%d", &n) != EOF) {
        printf("%d", dp[n]);
    }
    return 0;
}
