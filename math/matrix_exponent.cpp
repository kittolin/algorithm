/*
* 名称：矩阵幂

* 链接：http://t.cn/Aip4T3HX
* 难度：中等
* 算法：类比整数的快速幂
*/

#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 15;

struct Matrix {
    int rows;
    int cols;
    int arr[MAXN][MAXN];
    Matrix(int r, int c): rows(r), cols(c) {}
};

// !!! 传递的参数是指针
void InputMatrix(Matrix &m) {
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            scanf("%d", &m.arr[i][j]);
        }
    }
}

void OutputMatrix(Matrix m) {
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            if (j == 0) {
                printf("%d", m.arr[i][j]);
            } else {
                printf(" %d", m.arr[i][j]);
            }
        }
        printf("\n");
    }
}

Matrix Multiply(Matrix a, Matrix b) {
    Matrix c(a.rows, b.cols);
    for (int i = 0; i < c.rows; i++) {
        for (int j = 0; j < c.cols; j++) {
            c.arr[i][j] = 0;
            for (int k = 0; k < a.cols; k++) {
                // a 的第 i 行和 b 的第 j 列两两相乘累加
                c.arr[i][j] += a.arr[i][k] * b.arr[k][j];
            }
        }
    }
    return c;
}

Matrix FastExponentiation(Matrix m, int k) {
    Matrix e(m.rows, m.cols);
    // 单位阵类比整数的 1
    for (int i = 0; i < e.rows; i++) {
        for (int j = 0; j < e.cols; j++) {
            if (i == j) {
                e.arr[i][j] = 1;
            } else {
                e.arr[i][j] = 0;
            }
        }
    }

    while (k) {
        if (k % 2) {
            e = Multiply(e, m);
        }
        m = Multiply(m, m);
        k /= 2;
    }
    return e;
}

int main() {
    int n, k;
    while (scanf("%d %d", &n, &k) != EOF) {
        Matrix m(n, n);
        InputMatrix(m);
        OutputMatrix(FastExponentiation(m, k));
    }
    return 0;
}
