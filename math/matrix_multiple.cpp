/*
* 名称：计算两个矩阵的乘积
* 来源：哈尔滨工业大学复试上机题
* 链接：http://t.cn/Aip450PJ
* 难度：简单
*/

#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 5;

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
            printf("%d ", m.arr[i][j]);
        }
        printf("\n");
    }
}

Matrix Add(Matrix a, Matrix b) {
    Matrix c(a.rows, a.cols);
    for (int i = 0; i < c.rows; i++) {
        for (int j = 0; j < c.cols; j++) {
            c.arr[i][j] = a.arr[i][j] + b.arr[i][j];
        }
    }
    return c;
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

Matrix Transpose(Matrix m) {
    Matrix t(m.cols, m.rows);
    for (int i = 0; i < t.rows; i++) {
        for (int j = 0; j < t.cols; j++) {
            t.arr[i][j] = m.arr[j][i];
        }
    }
    return t;
}

int main() {
    Matrix a(2, 3);
    Matrix b(3, 2);
    InputMatrix(a);
    InputMatrix(b);
    Matrix c = Multiply(a, b);
    OutputMatrix(c);
    return 0;
}
