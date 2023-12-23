/*
* 名称：查找

* 链接：http://t.cn/E9g8aaR
* 难度：简单
*/

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 100 + 10;
int arr[MAXN];

bool LinearSearch(int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return true;
        }
    }
    return false;
}

// 从小到大排序
bool BinarySearch(int n, int target) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (target < arr[mid]) {
            right = mid - 1;
        } else if (target > arr[mid]) {
            left = mid + 1;
        } else {
            return true;
        }
    }
    return false;
}

int main() {
    int n, m;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) {
            int num;
            scanf("%d", &num);
            arr[i] = num;
        }
        sort(arr, arr + n);

        scanf("%d", &m);
        while (m --) {
            int target;
            scanf("%d", &target);
            if (BinarySearch(n, target)) {
                printf("YES\n");
            } else {
                printf("NO\n");
            }
        }
    }
    return 0;
}
