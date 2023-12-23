/*
* 名称：反序数

* 链接：http://t.cn/E9WBrut
* 难度：中等
*/

#include <iostream>
#include <cstdio>

using namespace std;

int ReversalOrdinal(int number) {
    int ans = 0;
    while (number) {
        ans = ans * 10 + number % 10;
        number /= 10;
    }
    return ans;
}

int main() {
    for (int n = 1000; n < 10000; n++) {
        if (n * 9 == ReversalOrdinal(n)) {
            printf("%d\n", n);
        }
    }
    return 0;
}
