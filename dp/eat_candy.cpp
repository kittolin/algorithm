/*
* 名称：吃糖果
* 来源：北京大学复试上机题
* 链接：http://985.so/ka45
* 难度：简单
*/

#include <cstdio>

using namespace std;

const int MAXN = 20;
int dp[MAXN];

void Initial() {
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i < MAXN; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
}

int main() {
    Initial();
    int n;
    while (scanf("%d", &n) != EOF) {
        printf("%d\n", dp[n]);
    }
    return 0;
}
