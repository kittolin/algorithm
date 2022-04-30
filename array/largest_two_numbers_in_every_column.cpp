/*
* 名称：矩阵每列最大的两个数
* 来源：华中科技大学复试上机题
* 链接：http://985.so/k7gq
* 难度：困难
*/

#include <cstdio>

using namespace std;

const int MAXN = 5;

struct Matrix {
    int arr[MAXN][MAXN];
    int rows;
    int cols;
    Matrix(int r, int c): rows(r), cols(c) {}
};

void InputMatrix(Matrix& m) {
    // 第一行第一列不需要再输入了
    for (int j = 1; j < m.cols; j++) {
        scanf("%d", &m.arr[0][j]);
    }
    for (int i = 1; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            scanf("%d", &m.arr[i][j]);
        }
    }
}

void OutputMatrix(const Matrix& m) {
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            printf("%d ", m.arr[i][j]);
        }
        printf("\n");
    }
}

void SolveMatrix(const Matrix& x, Matrix& y) {
    for (int j = 0; j < x.cols; j++) {
        // int max = 0;    // 最大数的下标
        // for (int i = 1; i < x.rows; i++) {
        //     if (x.arr[i][j] > x.arr[max][j]) {
        //         max = i;
        //     }
        // }

        // int next = -1;   // 次大数的下标，初始化为 -1 是用于防止 max 刚好等于 0 的情况
        // for (int i = 0; i < x.rows; i++) {
        //     if (i != max && (next == -1 || x.arr[i][j] > x.arr[next][j])) {
        //         next = i;
        //     }
        // }

        int max = x.arr[0][j] > x.arr[1][j]? 0: 1;   // 最大值的下标
        int next = x.arr[0][j] > x.arr[1][j]? 1: 0;  // 次大值的下标
        for (int i = 2; i < x.rows; i++) {
            if (x.arr[i][j] > x.arr[next][j]) {
                if (x.arr[i][j] > x.arr[max][j]) {   // 当前值大于最大值
                    next = max;
                    max = i;
                } else {    // 当前值大于次大值，小于最大值
                    next = i;
                }
            }
        }

        y.arr[0][j] = max > next? x.arr[next][j]: x.arr[max][j];  // 存放下标较小者
        y.arr[1][j] = max > next? x.arr[max][j]: x.arr[next][j];  // 存放下标较大者
    }
}

int main() {
    int number;
    while (scanf("%d", &number) != EOF) {
        Matrix x(4, 5);
        x.arr[0][0] = number;
        InputMatrix(x);
        Matrix y(2, 5);
        SolveMatrix(x, y);
        OutputMatrix(y);
    }
    return 0;
}
