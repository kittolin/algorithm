/*
* 名称：数字反转加和是否等于和的反转
* 来源：上海交通大学复试上机题
* 链接：http://985.so/9z66
* 难度：中等
*/

#include <cstdio>

using namespace std;

int ReversalNum(int num) {
    int ans = 0;
    while (num) {
        ans = ans * 10 + num % 10;
        num /= 10;
    }
    return ans;
}

int main() {
    int a, b;
    while (scanf("%d %d", &a, &b) != EOF) {
        if (ReversalNum(a) + ReversalNum(b) == ReversalNum(a + b)) {
            printf("%d\n", a + b);
        } else {
            printf("NO\n");
        }
    }
    return 0;
}
