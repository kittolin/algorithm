/*
* 名称：两个整数的末尾 k 位是否相同

* 链接：http://985.so/km05
* 难度：较难
*/

#include <cstdio>

using namespace std;

bool SameMantissa(int a, int b, int k) {
    int mod = 1;
    while (k--) {
        mod *= 10;
    }
    return a % mod == b % mod;
}

int main() {
    int a, b, k;
    while (scanf("%d %d %d", &a, &b, &k) != EOF) {
        if (a == 0 && b == 0) {
            break;
        }
        if (SameMantissa(a, b, k)) {
            printf("%d\n", -1);
        } else {
            printf("%d\n", a + b);
        }
    }
    return 0;
}
