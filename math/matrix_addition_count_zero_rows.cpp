/*
* 名称：A+B for Matrices

* 链接：http://985.so/kb0t
* 难度：中等
*/

#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 10 + 5;

int colsZeros[MAXN];    // 统计每一列有多少个 0

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

int MatrixAddition(const Matrix& a, const Matrix& b) {
    memset(colsZeros, 0, sizeof(colsZeros));
    int count = 0;

    // 统计零行
    for (int i = 0; i < a.rows; i++) {
        int zeros = 0;  // 统计每一行有多少个 0
        for (int j = 0; j < a.cols; j++) {
            if (a.arr[i][j] + b.arr[i][j] == 0) {
                zeros ++;
                colsZeros[j] ++;
            }
        }
        if (zeros == a.cols) {
            count ++;
        }
    }

    // 统计零列
    for (int j = 0; j < a.cols; j++) {
        if (colsZeros[j] == a.rows) {
            count ++;
        }
    }
    return count;
}

int main() {
    int m, n;
    while (scanf("%d", &m) != EOF) {
        if (m == 0) {
            break;
        }
        scanf("%d", &n);
        Matrix a(m, n);
        Matrix b(m, n);
        InputMatrix(a);
        InputMatrix(b);
        printf("%d\n", MatrixAddition(a, b));
    }
    return 0;
}
