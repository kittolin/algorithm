/*
* 名称：素数判断
* 来源：哈尔滨工业大学复试上机题
* 链接：http://t.cn/AiCuWE0Q
* 难度：中等
*/

#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

bool IsPrime(int n) {
    if (n < 2) {
        return false;
    }

    int bound = sqrt(n);
    for (int i = 2; i <= bound; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        if (IsPrime(n)) {
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }
    return 0;
}
