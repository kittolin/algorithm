/*
* 名称：Radar Installation
* 来源：北京大学 POJ
* 链接：http://poj.org/problem?id=1328
* 分析：海岸线无限长，岛屿数量有限，故从岛屿角度出发，记录每个岛屿的雷达可行安装区间
* 算法：区间贪心，在允许区间重叠的情况下选择最少的区间
*      (1)每次只选一个区间
*      (2)选择左端点最小的区间
*      (3)重叠区间的数目
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAXN = 1000 + 10;

// 岛屿的雷达安装可行区间
struct Interval {
    double left;
    double right;
};
Interval arr[MAXN];

bool Compare(Interval x, Interval y) {
    return x.left < y.left;
}

int Greedy(int n, int d) {
    sort(arr, arr + n, Compare);
    // 安装第一个雷达
    double curPosition = arr[0].right;
    int count = 1;

    for (int i = 1; i < n; i++) {
        if (arr[i].left <= curPosition) {
            // |---------|
            //    |---|
            if (arr[i].right < curPosition) {
                curPosition = arr[i].right;
            }
        } else {    // 前后两个区间没有重叠，需要安装新的雷达
            curPosition = arr[i].right;
            count ++;
        }
    }
    return count;
}

int main() {
    int n, d;
    int caseNumber = 1;
    while (scanf("%d %d", &n, &d) != EOF) {
        if (n == 0 && d == 0) {
            break;
        }

        bool flag = true;     // 是否能找到可行的雷达安装方案
        for (int i = 0; i < n; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            if (y > d) {
                flag = false; // 只要有一个岛屿的范围与海岸线相离，一定不可行
                // break;     // 不能 break，要将该组的后续数据输入完，否则会影响下一组样例
            } else {
                double r = sqrt(d * d * 1.0 - y * y);
                arr[i].left = x - r;
                arr[i].right = x + r;
            }
        }

        if (flag) {
            printf("Case %d: %d\n", caseNumber++, Greedy(n ,d));
        } else {
            printf("Case %d: %d\n", caseNumber++, -1);
        }
    }
    return 0;
}
