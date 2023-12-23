/*
* 名称：成绩排序

* 链接：http://985.so/96xn
* 难度：较难
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int MAXN = 1000 + 10;

struct Student {
    string name;
    int age;
    int score;
    bool operator<(const Student& s) const {
        if (score != s.score) {
            return score < s.score;
        }
        if (name != s.name) {
            return name < s.name;
        }
        return age < s.age;
    }
};
Student stus[MAXN];

int main() {
    int n;
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            cin >> stus[i].name >> stus[i].age >> stus[i].score;
        }
        sort(stus, stus + n);
        for (int i = 0; i < n; i++) {
            cout << stus[i].name << " " << stus[i].age << " " << stus[i].score << endl;
        }
    }
    return 0;
}
