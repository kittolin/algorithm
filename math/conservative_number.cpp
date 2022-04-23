/*
* 名称：守形数
* 来源：华中科技大学复试上机题
* 链接：http://985.so/9vxs
* 难度：简单
*/

#include <cstdio>

using namespace std;

bool IsConservative(int n) {
    int mod = 1, temp = n;
    while (temp) {
        mod *= 10;  // 25 的 mod 为 100
        temp /= 10;
    }
    return n * n % mod == n;
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        if (IsConservative(n)) {
            printf("Yes!\n");
        } else {
            printf("No!\n");
        }
    }
    return 0;
}
