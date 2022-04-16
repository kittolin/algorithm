/*
* 名称：Brainman
* 来源：北京大学 POJ
* 链接：http://poj.org/problem?id=1804
* 分析：将一个序列的相邻元素两两交换得到有序序列，最少的交换次数，即是求逆序数。
*/

#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 1000 + 10;
int arr[MAXN];
int tmp[MAXN];
int number;

void Combine(int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {  // <= 保证排序算法的稳定性
            tmp[k++] = arr[i++];
        } else {
            number += (mid + 1 - i);
            tmp[k++] = arr[j++];
        }
    }
    while(i <= mid) {
        tmp[k++] = arr[i++];
    }
    while(j <= right) {
        tmp[k++] = arr[j++];
    }

    // 复制回原数组
    for (k = left; k <= right; k++) {
        arr[k] = tmp[k];
    }
}

void MergeSort(int left, int right) {
    // 只有一个元素，自然是有序的
    if (left == right) {
        return;
    }
    int mid = left + (right - left) / 2;
    MergeSort(left, mid);
    MergeSort(mid + 1, right);
    Combine(left, mid, right);   
}

int main() {
    int cases, n;
    scanf("%d", &cases);
    for(int t = 1; t <= cases; t++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        number = 0;
        MergeSort(0, n - 1);
        printf("Scenario #%d:\n", t);
        printf("%d\n\n", number);
    }
    return 0;
}
