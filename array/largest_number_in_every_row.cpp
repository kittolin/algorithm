/*
* 名称：矩阵最大值

* 链接：http://985.so/k7e6
* 难度：较难
*/

#include <cstdio>

using namespace std;

const int MAXM = 100 + 10;
const int MAXN = 100 + 10;

int arr[MAXM][MAXN];

int main() {
    int m, n;
    while (scanf("%d %d", &m, &n) != EOF) {
        for (int i = 0; i < m; i++) {
            int max = 0, sum = 0;  // 当前行最大值的下标，当前行的累和
            for (int j = 0; j < n; j++) {
                scanf("%d", &arr[i][j]);
                if (arr[i][j] > arr[i][max]) {
                    max = j;
                }
                sum += arr[i][j];
            }
            arr[i][max] = sum;

            for (int j = 0; j < n; j++) {
                printf("%d ", arr[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
