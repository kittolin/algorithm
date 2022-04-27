/*
* 名称：Digital Roots
* 来源：北京大学复试上机题
* 链接：http://985.so/kg1h
* 难度：入门
*/

#include <cstdio>

using namespace std;

int DigitalRoot(int number) {
    if (number >= 1 && number <= 9) {
        return number;
    }
    int sum = 0;
    while (number) {
        sum += number % 10;
        number /= 10;
    }
    return DigitalRoot(sum);
}

int main() {
    int number;
    while (scanf("%d", &number) != EOF) {
        printf("%d\n", DigitalRoot(number));
    }
    return 0;
}
