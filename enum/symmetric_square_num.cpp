/*
* 名称：对称平方数
* 来源：清华大学复试上机题
* 链接：http://t.cn/E9lUYRn
* 难度：中等
*/

#include <iostream>
#include <cstdio>

using namespace std;

const int BOUND = 256;

int ReversalOrdinal(int number) {
    int ans = 0;
    while (number) {
        ans = ans * 10 + number % 10;
        number /= 10;
    }
    return ans;
}

bool SymmetricSquareNum(int num) {
    return num * num == ReversalOrdinal(num * num);
}

int main() {
    for (int i = 0; i <= BOUND; i++) {
        if (SymmetricSquareNum(i)) {
            printf("%d\n", i);
        }
    }
    return 0;
}
