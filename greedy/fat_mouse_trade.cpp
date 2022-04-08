/*
* 名称：FatMouse' Trade
* 来源：杭电 ACM
* 链接：http://acm.hdu.edu.cn/showproblem.php?pid=1009
* 算法：(1)每次购买一件商品
*      (2)选性价比最高的商品
*      (3)已经购买商品的累和
*/

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct JavaBean {
    double value;   // 不能用 int，否则会导致 Compare 函数计算精度丢失
    double cost;
};

const int MAXN = 1000 + 10;
JavaBean rooms[MAXN];

bool Compare(JavaBean a, JavaBean b) {
    return (a.value / a.cost) > (b.value / b.cost);
}

double Greedy(int m, int n) {
    // 按性价比降序排列
    sort(rooms, rooms + n, Compare);

    double result = 0.0;
    for(int i = 0; i < n; i++) {
        // 够买的全买，不够买的按比例买
        if (m >= rooms[i].cost) {
            result += rooms[i].value;
            m -= rooms[i].cost;
        } else {
            result += (m / rooms[i].cost * rooms[i].value);
            m = 0;  // !!! m = 0 不能放到 result 更新前
            break;
        }
    }
    return result;  
}

int main() {
    int m, n;
    while(scanf("%d %d", &m, &n) != EOF) {
        if (m == -1 && n == -1) {
            break;
        }
        for(int i = 0; i < n; i++) {
            scanf("%lf %lf", &rooms[i].value, &rooms[i].cost);
        }
        printf("%.3f\n", Greedy(m, n));
    }

    return 0;
}
