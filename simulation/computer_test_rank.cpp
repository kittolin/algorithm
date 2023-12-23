/*
* 名称：上机考试合格考生排名

* 链接：http://985.so/k0e8
* 难度：中等
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int MAXM = 15;
const int MAXN = 1000 + 10;

struct Examinee {
    string number;
    int totalScore;
    Examinee() {};    // examinees 数组初始化用到的
    Examinee(string n, int t): number(n), totalScore(t) {}
    bool operator<(const Examinee& e) const {
        if (totalScore == e.totalScore) {
            return number < e.number;
        }
        return totalScore > e.totalScore;
    }
};

int scores[MAXM];   // 考题的分值
Examinee examinees[MAXN];

int main() {
    int n, m, line, ACs, number;
    string examineeNum;
    while (cin >> n >> m >> line) {
        if (n == 0) {
            break;
        }
        for (int i = 1; i <= m; i++) {
            cin >> scores[i];
        }

        int passNum = 0;
        while (n --) {
            cin >> examineeNum >> ACs;
            int totalScore = 0;
            while (ACs --) {
                cin >> number;
                totalScore += scores[number];
            }
            if (totalScore >= line) {
                examinees[passNum++] = Examinee(examineeNum, totalScore);
            }
        }

        sort(examinees, examinees + passNum);
        cout << passNum << endl;
        for (int i = 0; i < passNum; i++) {
            cout << examinees[i].number << " " << examinees[i].totalScore << endl;
        }
    }
    return 0;
}
