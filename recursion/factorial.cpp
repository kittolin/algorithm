/*
* 名称：n的阶乘

* 链接：http://t.cn/Ai0ocOUY
* 难度：简单
*/

#include <iostream>
#include <cstdio>

using namespace std;

// !!! 阶乘结果非常大，需要用 long long
long long Factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * Factorial(n - 1);
}

int main() {
    int n;
    while (scanf("%d",&n) != EOF) {
        printf("%lld\n", Factorial(n));
    }
    return 0;
}
