/*
* 名称：排序
* 来源：华中科技大学复试上机题
* 链接：http://t.cn/E9dLx5K
* 难度：较难
*/

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 100 + 10;
int arr[MAXN];

// 归并排序 TODO

// 快速排序 TODO

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) {
            int num;
            scanf("%d",&num);
            arr[i] = num;
        }
    }
    sort(arr, arr + n);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
