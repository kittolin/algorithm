/*
* 名称：旋转矩阵
* 来源：北京航天航空大学复试上机题
* 链接：http://985.so/95x1
* 难度：较难
*/

#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 10;

struct Matrix {
    int rows;
    int cols;
    int arr[MAXN][MAXN];
    Matrix(int r, int c): rows(r), cols(c) {}
};

void InputMatrix(Matrix& m) {
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            scanf("%d", &m.arr[i][j]);
        }
    }
}

vector<int> NewCoordinateAfterRotate(int n, int i, int j, int angle) {
    vector<int> nij;
    int ni = i, nj = j;
    if (angle == 90) {
        ni = j;          // 原先的第 j 列旋转为新矩阵的第 j 行
        nj = n - 1 - i;  // 原先的第 i 行旋转为新矩阵的第 n-1-i 列
    } else if (angle == 180) {
        ni = n - 1 - i;
        nj = n - 1 - j;
    } else if (angle == 270) {
        ni = n - 1 - j;
        nj = i;
    }
    nij.push_back(ni);
    nij.push_back(nj);
    return nij;
}

bool EqualAfterRotate(const Matrix& x, const Matrix& y, int angle) {
    for (int i = 0; i < x.rows; i++) {
        for (int j = 0; j < x.cols; j++) {
            vector<int> nij = NewCoordinateAfterRotate(x.rows, i, j, angle);
            int ni = nij[0], nj = nij[1];
            if (x.arr[i][j] != y.arr[ni][nj]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        Matrix x(n, n);
        Matrix y(n, n);
        InputMatrix(x);
        InputMatrix(y);
        int angle = 0;
        while (angle < 360) {
            if (EqualAfterRotate(x, y, angle)) {
                printf("%d\n", angle);
                break;
            } else {
                angle += 90;
            }
        }
        if (angle >= 360) {
            printf("%d\n", -1);
        }
    }
    return 0;
}
