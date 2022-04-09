/*
* 名称：汉诺塔 III
* 来源：杭电 ACM
* 链接：http://acm.hdu.edu.cn/showproblem.php?pid=2064
* 递归算法：(1)将 A 上的 n-1 个圆盘移动 A->B->C，移动 F(n-1)次；
*         (2)将 A 上的最后一个圆盘移动到 B，移动 1 次；
*         (3)将 C 上的 n-1 个圆盘移动 C->B->A，移动 F(n-1)次；
*         (4)将 B 的唯一一个圆盘移动到 C，移动 1 次；
*         (5)将 A 上的 n-1 个圆盘移动 A->B->C，移动 F(n-1)次；
* 公式推导：(1) F(n) = 3 * F(n-1) + 2 -> F(n) + 1 = 3 * (F(n-1) + 1)
*         (2) 令 G(n) = F(n) + 1, 则 G(n) = 3 * G(n-1) -> G(n) = G(1) * 3 ^ (n-1) = 3 ^ n
*         (3) F(n) = 3 ^ n - 1
*/

#include <iostream>
#include <cstdio>
#include <math.h>

using namespace std;

// 递归
long long Recursion(int n) {
    if (n == 1) {
        return 2;
    }
    return 3 * Recursion(n - 1) + 2;
}

// 公式推导
// ??? 当 n = 35 时，结果出错
long long Formula(int n) {
    return pow(3, n) - 1;
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        printf("%lld\n", Recursion(n));
    }
    return 0;
}
