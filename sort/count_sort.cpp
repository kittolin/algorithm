/*
* 名称：从大到小输出前 m 大的数

* 链接：https://acm.hdu.edu.cn/showproblem.php?pid=1425
*/

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 1e6 + 10;
const int OFFSET = 5e5;  // 将数字范围偏移到从 0 开始
const int RANGE = OFFSET * 2 + 10;

// int arr[MAXN];
int numbers[RANGE];       // 辅助数组，用于计数

int main() {
    int n, m, num;
    while (scanf("%d %d", &n, &m) != EOF) {
        memset(numbers, 0, sizeof(numbers));
        for (int i = 0; i < n; i++) {
            // scanf("%d", &arr[i]);
            scanf("%d", &num);
            numbers[num + OFFSET] ++;  // 计数
        }

        int count = 0;
        int index = RANGE - 1;
        while (index >= 0) {
            if (numbers[index]) {   // 在这里面 index 不能减 1，因为可能有多个相同的数
                if (count == 0) {
                    printf("%d", index - OFFSET);
                } else {
                    printf(" %d", index - OFFSET);
                }
                numbers[index] --;
                count ++;
            } else {
                index --;
            }

            if (count == m) {
                break;
            }
        }
        printf("\n");

        // // 排序
        // int index = 0;
        // for (int i = 0; i < RANGE; i++) {
        //     while (numbers[i] --) {
        //         arr[index ++] = i - OFFSET;
        //     }
        // }

        // for (int i = n - 1; i >= n - m; i --) {
        //     if (i == n - m) {
        //         printf("%d\n", arr[i]);
        //     } else {
        //         printf("%d ", arr[i]);
        //     }
        // }
    }
    return 0;
}
