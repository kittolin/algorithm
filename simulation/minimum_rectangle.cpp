/*
* 名称：最小长方形

* 链接：http://985.so/kbc7
* 难度：简单
*/

#include <iostream>
#include <cstdio>

using namespace std;

const int BOUND = 1e18;

int xMax, xMin, yMax, yMin;
bool flag;  // 当前测试用例是否有坐标输入

void Initial() {
    xMax = yMax = -BOUND;
    xMin = yMin = BOUND;
    flag = false;
}

int main() {
    Initial();
    int x, y;
    while (scanf("%d %d", &x, &y) != EOF) {
        if (x == 0 && y == 0) {
            if (!flag) {
                break;
            }
            printf("%d %d %d %d\n", xMin, yMin, xMax, yMax);
            Initial();
        } else {
            xMax = max(xMax, x);
            xMin = min(xMin, x);
            yMax = max(yMax, y);
            yMin = min(yMin, y);
            flag = true;
        }
    }
    return 0;
}

