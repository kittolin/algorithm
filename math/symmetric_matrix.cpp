/*
* 名称：对称矩阵
* 来源：华中科技大学复试上机题
* 链接：http://985.so/9v9g
* 难度：中等
*/

#include <cstdio>

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
        for(int j = 0; j < m.cols; j++) {
            scanf("%d", &m.arr[i][j]);
        }
    }
}

bool IsSymmetric(const Matrix& m) {
    for (int i = 0; i < m.rows; i++) {
        for(int j = 0; j < m.cols; j++) {
            if (m.arr[i][j] != m.arr[j][i]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        Matrix m(n, n);
        InputMatrix(m);
        if (IsSymmetric(m)) {
            printf("Yes!\n");
        } else {
            printf("No!\n");
        }
    }
    return 0;
}
