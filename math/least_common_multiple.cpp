/*
* 名称：最小公倍数(LCM)

* 链接：https://acm.hdu.edu.cn/showproblem.php?pid=1108
*/

#include <iostream>
#include <cstdio>

using namespace std;

// 辗转相除法(欧几里得算法)
int GCD(int a, int b) {
    while (a % b) {
        int r = a % b;
        a = b;
        b = r;
    }
    return b;
}

int LCM(int a, int b) {
    return a * b / GCD(a, b);
}

int main() {
    int a, b;
    while (scanf("%d %d", &a, &b) != EOF) {
        printf("%d\n", LCM(a, b));
    }
    return 0;
}
