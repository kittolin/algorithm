/*
* 名称：两升序序列的中位数

* 链接：http://985.so/k1gy
* 难度：中等
* 算法：归并排序的 merge 思想
*/

#include <cstdio>

using namespace std;

const int MAXN = 1e6 + 10;

int arr1[MAXN];
int arr2[MAXN];

int GetMedian(int n1, int n2) {
    int index = (n1 + n2) % 2? (n1 + n2) / 2: (n1 + n2) / 2 - 1;  // 合并数组中中位数的索引
    int i1 = 0, i2 = 0, j = -1;
    bool inArr1;
    // 模拟两数组归并的过程
    while (i1 < n1 && i2 < n2) {
        if (arr1[i1] < arr2[i2]) {
            i1 ++;
            inArr1 = true;
        } else {
            i2 ++;
            inArr1 = false;
        }
        if (++j == index) {
            return inArr1? arr1[i1 -1]: arr2[i2 - 1];
        }
    }
    while (i1 < n1) {
        i1 ++;
        if (++j == index) {
            return arr1[i1 - 1];
        }
    }
    while (i2 < n2) {
        i2 ++;
        if (++j == index) {
            return arr2[i2 - 1];
        }
    }
    return -1;
}

int main() {
    int n1, n2;
    while (scanf("%d", &n1) != EOF) {
        for (int i = 0; i < n1; i++) {
            scanf("%d", &arr1[i]);
        }
        scanf("%d", &n2);
        for (int i = 0; i < n2; i++) {
            scanf("%d", &arr2[i]);
        }
        printf("%d\n", GetMedian(n1, n2));
    }
    return 0;
}
