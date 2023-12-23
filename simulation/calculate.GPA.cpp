/*
* 名称：学分绩点

* 链接：http://985.so/kuxk
* 难度：简单
*/

#include <cstdio>

using namespace std;

const int MAXN = 15;
int credits[MAXN];  // 记录每门课程的学分

// double Score2GPA(int score) {
//     double GPA;
//     if (score >= 90) {
//         GPA = 4.0;
//     } else if (score >= 85) {
//         GPA = 3.7;
//     } else if (score >= 82) {
//         GPA = 3.3;
//     } else if (score >= 78) {
//         GPA = 3.0;
//     } else if (score >= 75) {
//         GPA = 2.7;
//     } else if (score >= 72) {
//         GPA = 2.3;
//     } else if (score >= 68) {
//         GPA = 2.0;
//     } else if (score >= 64) {
//         GPA = 1.5;
//     } else if (score >= 60) {
//         GPA = 1.0;
//     } else {
//         GPA = 0;
//     }
//     return GPA;
// }

double map[9][2] = {
    {90, 4.0}, {85, 3.7}, {82, 3.3}, {78, 3.0}, {75, 2.7},
    {72, 2.3}, {68, 2.0}, {64, 1.5}, {60, 1.0}
};

double Score2GPA(int score) {
    for (int i = 0; i < 10; i++) {
        if (score >= map[i][0]) {
            return map[i][1];
        }
    }
    return 0;
}

int main() {
    int n, score, totalCredit = 0;
    double totalGPA = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &credits[i]);
        totalCredit += credits[i];
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &score);
        totalGPA += Score2GPA(score) * credits[i];
    }
    printf("%.2f", totalGPA / totalCredit);
    return 0;
}
