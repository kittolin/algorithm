/*
* 名称：中位数

* 链接：http://985.so/ka52
* 难度：中等
* 分析：没必要进行排序，只要能找到排好序后索引为 n/2 和 n/2-1 的元素即可。
*/

#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

const int MAXN = 10000 + 10;
int arr[MAXN];

int Partition(int left, int right) {
    int pivot = left + rand() % (right - left + 1);
    swap(arr[left], arr[pivot]);
    while (left < right) {
        while (left < right && arr[left] <= arr[right]) {
            right --;
        }
        swap(arr[left], arr[right]);
        while (left < right && arr[left] <= arr[right]) {
            left ++;
        }
        swap(arr[left], arr[right]);
    }
    return left;
}

int KthNumInSortArr(int left, int right, int index) {
    int pos = Partition(left, right);
    if (pos > index) {
        return KthNumInSortArr(left, pos - 1, index);
    } else if (pos < index) {
        return KthNumInSortArr(pos + 1, right, index);
    } else {
        return arr[pos];
    }
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

        int median;
        if (n % 2) {
            median = KthNumInSortArr(0, n - 1, n / 2);
        } else {
            median = (KthNumInSortArr(0, n - 1, n / 2 - 1) + KthNumInSortArr(0, n - 1, n / 2)) / 2;
        }
        printf("%d\n", median);
    }
    return 0;
}
