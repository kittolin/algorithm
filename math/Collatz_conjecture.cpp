/*
* 名称：考拉兹猜想

* 链接：http://985.so/kmk2
* 难度：入门
*/

#include <cstdio>

using namespace std;

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        int count = 0;
        while (n != 1) {
            if (n % 2) {
                n = (3 * n + 1) / 2;
            } else {
                n /= 2;
            }
            count ++;
        }
        printf("%d\n", count);
    }
    return 0;
}
