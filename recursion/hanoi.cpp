/*
* 名称：汉诺塔
* 描述：有 A、B、C 三根柱，将 A 上的 n 个圆盘借助 B 移动到 C 上，总共需要移动多少次？
* 递归算法：(1)将 A 上的 n-1 个圆盘移动到 B，移动 F(n - 1) 次；
*         (2)将 A 上的最后一个圆盘移动到 C，移动 1 次；
*         (3)将 B 上的 n-1 个圆盘移动到 C，移动 F(n - 1) 次；
* 公式推导：(1) F(n) = 2 * F(n-1) + 1 -> F(n) + 1 = 2 * (F(n-1) + 1)
*         (2) 令 G(n) = F(n) + 1, 则 G(n) = 2 * G(n-1) -> G(n) = G(1) * 2 ^ (n-1) = 2 ^ n
*         (3) F(n) = 2 ^ n - 1
*/

#include <iostream>
#include <cstdio>
#include <math.h>

using namespace std;

// 递归
long long Recursion(int n) {
    if (n == 1) {
        return 1;
    }
    return 2 * Recursion(n - 1) + 1;
}

// 公式推导
long long Formula(int n) {
    return pow(2, n) - 1;
}

int main() {
    int n;
    while (scanf("%d",&n) != EOF) {
        printf("%lld, ", Recursion(n));
        printf("%lld\n", Formula(n));
    }
    return 0;
}
