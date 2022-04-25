/*
* 名称：求最大最小数
* 来源：清华大学复试上机题
* 链接：http://985.so/kkhb
* 难度：中等
*/

#include <iostream>
#include <cstdio>

using namespace std;

const int BOUND = 1e6;

int main() {
    int n, number;
    while (scanf("%d", &n) != EOF) {
        int maximum = -BOUND, minimum = BOUND;
        while (n --) {
            scanf("%d", number);
            maximum = max(maximum, number);
            minimum = min(minimum, number);
        }
        printf("%d %d\n", maximum, minimum);
    }
    return 0;
}
