/*
* 名称：去除最大元素，并排序剩余元素
* 来源：华中科技大学复试上机题
* 链接：http://985.so/9cds
* 难度：困难
*/

#include <cstdio>
#include <algorithm>
#include <climits>

using namespace std;

const int MAXN = 1000 + 10;
const int INF = INT_MAX;
int arr[MAXN];

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        int max = -INF, index = -1;  // 记录最大元素及其下标
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
            if (arr[i] >= max) {     // 包括等于的情况，使得 index 尽量往后靠，减少移动次数
                max = arr[i];
                index = i;
            }
        }

        // 元素从后往前靠，覆盖掉最大元素
        for (int i = index; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        n --;

        printf("%d\n", max);
        if (n == 0) {
            printf("%d\n", -1);
        } else {
            sort(arr, arr + n);
            for (int i = 0; i < n; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
        }
    }
    return 0;
}
