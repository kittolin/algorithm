/*
* 名称：奇数阶乘累和和偶数阶乘累和
* 来源：华中科技大学复试上机题
* 链接：http://985.so/ktwn
* 难度：较难
*/

#include <cstdio>

using namespace std;

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        int oddFactorialSum = 0, evenFactorialSum = 0, factorial = 1;
        for (int i = 1; i <= n; i++) {
            factorial *= i; // 当前数字的阶乘
            if (i % 2) {
                oddFactorialSum += factorial;
            } else {
                evenFactorialSum += factorial;
            }
        }
        printf("%d %d\n", oddFactorialSum, evenFactorialSum);
    }
    return 0;
}
