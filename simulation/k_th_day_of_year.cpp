/*
* 名称：今年的第几天？
* 来源：清华大学复试上机题
* 链接：http://t.cn/E9jXK5A
* 难度：中等
*/

#include <iostream>
#include <cstdio>

using namespace std;

// 每个月有多少天，从 1 开始
int days[12 + 1] = {
    0, 31, 28, 31, 30,
    31, 30, 31, 31,
    30, 31, 30, 31
};

bool IsLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int KthDayOfYear(int year, int month, int day) {
    int ans = 0;
    // 累加前面各个月份的天数
    for (int m = 1; m < month; m++) {
        ans += days[m];
        // 闰年二月多一天
        if (m == 2 && IsLeapYear(year)) {
            ans += 1;
        }
    }
    ans += day;
    return ans;
}

int main() {
    int year, month, day;
    while (scanf("%d", &year) != EOF) {
        scanf("%d", &month);
        scanf("%d", &day);
        printf("%d\n", KthDayOfYear(year, month, day));
    }
    return 0;
}
