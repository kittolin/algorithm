/*
* 名称：日期差值

* 链接：http://985.so/x9ei
* 难度：中等
*/

#include <iostream>
#include <string>

using namespace std;

int daysTable[12 + 1] = {
    0, 31, 28, 31, 30,
    31, 30, 31, 31,
    30, 31, 30, 31
};

bool IsLeap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// 当前年的第几天
int KthDaysOfTheYear(int year, int month, int day) {
    int ans = 0;
    for (int i = 1; i < month; i++) {
        int days = daysTable[i];
        if (i == 2 && IsLeap(year)) {
            days ++;
        }
        ans += days;
    }
    return ans + day;
}

int DiffOfTwoDates(string startDate, string endDate) {
    int sYear = stoi(startDate.substr(0, 4));
    int sMonth = stoi(startDate.substr(4, 2));
    int sDay = stoi(startDate.substr(6, 2));
    int eYear = stoi(endDate.substr(0, 4));
    int eMonth = stoi(endDate.substr(4, 2));
    int eDay = stoi(endDate.substr(6, 2));

    if (sYear == eYear) {
        return KthDaysOfTheYear(eYear, eMonth, eDay) - KthDaysOfTheYear(sYear, sMonth, sDay) + 1;
    }

    int ans = 0;
    ans += 365 - KthDaysOfTheYear(sYear, sMonth, sDay) + 1; // eg: 2015-10-10 ~ 2015-12-31
    if (IsLeap(sYear)) {
        ans ++;
    }
    for (int i = sYear + 1; i < eYear; i++) { // eg: 2016-01-01 ~ 2021-12-31
        ans += 365;
        if (IsLeap(i)) {
            ans ++;
        }
    }
    return ans + KthDaysOfTheYear(eYear, eMonth, eDay); // eg: 2022-01-01 ~ 2022-05-05
}

int main() {
    string startDate, endDate;
    while (cin >> startDate >> endDate) {
        cout << DiffOfTwoDates(startDate, endDate) << endl;
    }
    return 0;
}
