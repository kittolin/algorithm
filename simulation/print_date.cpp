/*
* 名称：打印日期

* 链接：http://t.cn/E9YP2a8
* 难度：较难
*/

#include <iostream>
#include <cstdio>

using namespace std;

// 每个月有多少天，从 1 开始
int daysTable[12 + 1] = {
    0, 31, 28, 31, 30,
    31, 30, 31, 31,
    30, 31, 30, 31
};

bool IsLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

void PrintDate(int year, int n) {
    int month = 1;
    for (int i = 1; i <= 12; i++) {
        int days = daysTable[i];
        // 闰年二月多一天
        if (i == 2 && IsLeapYear(year)) {
            days ++;
        }
        // 不能用 >=，否则 n 可能会减成 0
        if (n > days) {
            n -= days;
            month ++;
        } else {
            break;
        }
    }
    printf("%04d-%02d-%02d\n", year, month, n);
}

int main() {
    int year, n;
    while (scanf("%d %d", &year, &n) != EOF) {
        PrintDate(year, n);
    }
    return 0;
}
