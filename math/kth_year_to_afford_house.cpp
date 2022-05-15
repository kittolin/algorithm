/*
* 名称：买房子
* 来源：北京大学复试上机题
* 链接：http://985.so/xcu6
* 难度：中等
*/

#include <cstdio>

using namespace std;

const int CAPITAL = 200;
const int TERM = 21;

int KthYearToAfford(int n, int k) {
    if (n >= CAPITAL) {
        return 1;
    }

    double price = CAPITAL;
    for (int i = 2; i <= TERM; i++) {
        price = price * (1 + k * 1.0 / 100);
        if (n * i >= price) {
            return i;
        }
    }
    return 0;
}

int main() {
    int n, k;
    while (scanf("%d %d", &n, &k) != EOF) {
        int year = KthYearToAfford(n, k);
        if (year > 0) {
            printf("%d\n", year);
        } else {
            printf("Impossible\n");
        }
    }
    return 0;
}
