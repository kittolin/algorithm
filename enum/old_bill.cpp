/*
* 题目：Old Bill
* 来源：上海交通大学复试上机题
* 链接：http://985.so/xwtv
* 难度：简单
*/

#include <cstdio>

using namespace std;

int MaxTotalPrice(int n, int x, int y, int z) {
    for (int i = 9; i > 0; i--) {
        for (int j = 9; j >= 0; j--) {
            int totalPrice = i * 10000 + x * 1000 + y * 100 + z * 10 + j;
            if (totalPrice % n == 0) {
                return totalPrice;
            }
        }
    }
    return 0;
}

int main() {
    int n, x, y, z;
    while (scanf("%d", &n) != EOF) {
        scanf("%d %d %d", &x, &y, &z);
        int totalPrice = MaxTotalPrice(n, x, y, z);
        if (totalPrice) {
            printf("%d %d %d\n", totalPrice / 10000, totalPrice % 10, totalPrice / n);
        } else {
            printf("%d\n", 0);
        }
    }
    return 0;
}

