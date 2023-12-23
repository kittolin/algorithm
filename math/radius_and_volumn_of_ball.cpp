/*
* 名称：球的半径和体积

* 链接：http://985.so/k47y
* 难度：较难
*/

#include <cstdio>
#include <cmath>

using namespace std;

const double PI = acos(-1);

int main() {
    double x0, y0, z0, x1, y1, z1, radius, volume;
    while (scanf("%lf %lf %lf %lf %lf %lf" , &x0, &y0, &z0, &x1, &y1, &z1) != EOF) {
        radius = sqrt((x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0) + (z1 - z0) * (z1 - z0));
        volume = radius * radius * radius * PI * 4 / 3;
        printf("%.3f %.3f", radius, volume);
    }
    return 0;
}
