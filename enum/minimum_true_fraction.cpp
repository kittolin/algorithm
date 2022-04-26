/*
* 名称：最简真分数个数
* 来源：北京大学复试上机题
* 链接：http://985.so/k8jg
* 难度：中等
* 分析：最简真分数，即分子小于分母，且分子和分母的最大公约数为 1
*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 600 + 10;
int arr[MAXN];

int GCD(int a, int b) {
    while (a % b) {
        int r = a % b;
        a = b;
        b = r;
    }
    return b;
}

int NumOfMinTrueFraction(int n) {
    sort(arr, arr + n);  // 先排序，之后的循环不用判断前面的数
    int count = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (GCD(arr[i], arr[j]) == 1) {
                count ++;
            }
        }
    }
    return count;
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        if (n == 0) {
            break;
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        printf("%d\n", NumOfMinTrueFraction(n));
    }
    return 0;
}
