/*
* 名称：Number Steps
* 来源：北京大学复试上机题
* 链接：http://985.so/xf18
* 难度：简单
*/

#include <cstdio>

using namespace std;

int NumberOfPoint(int x, int y) {
    if (x != y && y + 2 != x) {
        return -1;
    }

    // 只有 x == y 或者 y + 2 == x 时才有解，故 x 和 y 要么都是偶数，要么都是奇数
    if (x % 2) {
        return x + y - 1;
    } else {
        return x + y;
    }
}

int main() {
    int x, y;
    while (scanf("%d %d", &x, &y) != EOF) {
        int number = NumberOfPoint(x, y);
        if (number == -1) {
            printf("No Number\n");
        } else {
            printf("%d\n", number);
        }
    }
    return 0;
}

