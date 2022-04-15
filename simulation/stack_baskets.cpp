/*
* 名称：叠筐
* 来源：杭电 ACM
* 链接：http://acm.hdu.edu.cn/showproblem.php?pid=2074
* 难度：中等
*/

#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 80 + 10;
char matrix[MAXN][MAXN];

void PrintStackingBaskets(int n, char center, char outside) {
    // 填充 (n/2+1) 个圈
    for (int i = 0; i <= n /2; i++) {
        int j = n - 1 - i;
        int length = n - 2 * i;
        // 离中心距离为偶数的圈用 center 字符 
        char cur;
        if ((n / 2 - i) % 2 == 0) {
            cur = center;
        } else {
            cur = outside;
        }
        for (int k = 0; k < length; k++) {
            matrix[i][i + k] = cur; // 上边
            matrix[j][j - k] = cur; // 下边
            matrix[i + k][i] = cur; // 左边
            matrix[j - k][j] = cur; // 右边
        }
    }

    // 去掉四个角
    if (n != 1) {
        matrix[0][0] = ' ';
        matrix[0][n - 1] = ' ';
        matrix[n - 1][0] = ' ';
        matrix[n - 1][n - 1] = ' ';
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%c", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    char center, outside;
    bool firstCase = true;
    while (scanf("%d %c %c", &n, &center, &outside) != EOF) {
        // 第一个输入样例不需要先回车，其他样例需要
        if (firstCase) {
            firstCase = false;
        } else {
            printf("\n");
        }
        PrintStackingBaskets(n, center, outside);
    }
    return 0;
}
