/*
* 名称：矩阵就地转置

* 链接：http://985.so/96kp
* 难度：较难
*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 100 + 10;

struct Matrix {
    int arr[MAXN][MAXN];
    int rows;
    int cols;
    Matrix(int r, int c): rows(r), cols(c) {}
};

void InputMatrix(Matrix& m) {
    for (int i = 0; i < m.rows; i++) {
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

void Transpose(Matrix& m) {
    // 遍历矩阵的上三角元素，和下三角元素两两互换
    for (int i = 0; i < m.rows - 1; i++) {
        for (int j = i + 1; j < m.cols; j++) {
            swap(m.arr[i][j], m.arr[j][i]);
        }
    }
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        Matrix m(n, n);
        InputMatrix(m);
        Transpose(m);
        OutputMatrix(m);
    }
    return 0;
}
