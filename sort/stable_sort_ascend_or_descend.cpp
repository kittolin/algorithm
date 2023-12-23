/*
* 名称：成绩排序（稳定）

* 链接：http://985.so/kau2
* 难度：困难
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int MAXN = 200 + 10;

struct User {
    string name;
    int score;
    int order;  // sort 函数排序是不稳定的，故用 order 字段标记输入顺序
};

User users[MAXN];
int flag;

bool Compare(User a, User b) {
    if (a.score == b.score) {
        return a.order < b.order;
    }
    if (flag) {
        return a.score < b.score;
    }
    return a.score > b.score;
}

int main() {
    int n;
    while (cin >> n >> flag) {
        for (int i = 0; i < n; i++) {
            cin >> users[i].name >> users[i].score;
            users[i].order = i;
        }
        sort(users, users + n, Compare);
        for (int i = 0; i < n; i++) {
            cout << users[i].name << " " << users[i].score << endl;
        }
    }
    return 0;
}
