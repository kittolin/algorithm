/*
* 名称：C 翻转
* 来源：北京航天航空大学复试上机题
* 链接：http://985.so/95gb
* 难度：较难
*/

#include <cstdio>

using namespace std;

const int N = 5;
int arr[N + 1][N + 1];    // 下标从 1 开始
int buf[N + 1][N + 1];    // 暂存原先的矩阵，避免旋转过程中覆盖掉旧数据

void InputMatrix() {
    int i = 1, j = 2;     // 从第 1 行第 2 列开始输入
    for (int k = 2; k <= N * N; k++) {
        if (k % N == 1) { // 另起一行
            i++;
            j = 1;
        }
        int number;
        scanf("%d", &number);
        arr[i][j] = number;
        buf[i][j] = number;
        j++;
    }
}

void OutputRotatingMatrix(int flag, int length, int x, int y) {
    int nx = x + length - 1;
    int ny = y + length - 1;
    for (int i = x; i <= nx; i++) {
        for (int j = y; j <= ny; j++) {
            int ni, nj;
            if (flag == 1) { // 顺时针 90 度
                ni = x + (j - y);
                nj = ny - (i - x);
            } else {        // 逆时针 90 度
                ni = nx - (j - y);
                nj = y + (i - x);
            }
            arr[ni][nj] = buf[i][j];
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int first;
    while (scanf("%d", &first) != EOF) {
        arr[1][1] = buf[1][1] = first;
        InputMatrix();
        int flag, length, x, y;
        scanf("%d %d %d %d", &flag, &length, &x, &y);
        OutputRotatingMatrix(flag, length, x, y);
    }
    return 0;
}
