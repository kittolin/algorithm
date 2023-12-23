/*
* 名称：整数奇偶排序

* 链接：http://t.cn/E9glPvp
* 难度：中等 
*/

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 10;
int arr[N];

// 若返回 true，则 x 排在 y 的前面
bool Compare(int x, int y) {
    if (x % 2 == 1 && y % 2== 1) {
        return x > y;
    }
    if (x % 2 == 0 && y % 2 == 0) {
        return x < y;
    }
    return x % 2 > y % 2;
}

int main() {
    while (scanf("%d", &arr[0]) != EOF) {
        for (int i = 1; i < N; i++) {
            scanf("%d", &arr[i]);
        }
        sort(arr, arr + N, Compare);
        for (int i = 0; i < N; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    return 0;
}
