/*
* 名称：成绩排序
* 来源：清华大学复试上机题
* 链接：http://t.cn/E9d3ysv
* 难度：中等
*/

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct Student {
    int number;
    int score;
    bool operator<(Student s) const {
        if (score == s.score) {
            return number < s.number;
        }
        return score < s.score;
    }
};

const int MAXN = 100 + 10;
Student students[MAXN];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        Student s;
        scanf("%d %d", &s.number, &s.score);
        students[i] = s;
    }
    sort(students, students + n);
    for (int i = 0; i < n; i++) {
        printf("%d %d\n", students[i].number, students[i].score);
    }
    return 0;
}
