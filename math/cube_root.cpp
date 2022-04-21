/*
* 名称：求解立方根
* 来源：北京航天航空大学复试上机题
* 链接：http://985.so/950d
* 难度：中等
* 算法：二分查找，注意输入小于 1 的情况
*/

#include <cstdio>

using namespace std;

const double PRECISION = 0.001; // 用 0.01 有些样例不通过

double SolveCubeRoot(double number) {
    double abs = number >= 0 ? number: -1 * number; // 求绝对值
    double min = 0;
    double max = abs >= 1? abs: 1;  // 0.3 的立方根为 0.7，大于 0.3，故将 max 设为 1

    // 左右指针不断逼近直到满足精度
    while ((max - min) > PRECISION) {
        double mid = (min + max) / 2;
        double cube = mid * mid * mid;
        if (cube > abs) {
            max = mid;
        } else if (cube < abs) {
            min = mid;
        } else {
            return number >= 0 ? mid: -1 * mid;
        }
    }
    return number >= 0 ? min: -1 * min;
}

int main() {
    double number;
    scanf("%lf", &number);
    printf("%.1f\n", SolveCubeRoot(number));
    return 0;
}
