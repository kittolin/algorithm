/*
* 名称：最大公约数(GCD)

* 链接：http://t.cn/AiCuWLTS
* 难度：简单
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

int main() {
    int a, b;
    while (scanf("%d %d", &a, &b) != EOF) {
        printf("%d\n", GCD(a, b));
    }
    return 0;
}
