/*
* 名称：Graduate Admission

* 链接：http://985.so/kim8
* 难度：中等
*/

#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

const int MAXN = 40000;
const int MAXM = 100;
const int MAXK = 5;

struct Student {
    int number;  // 编号，即输入的顺序
    int GE;
    int GI;
    int grade;
    int rank;   // 最终排名
    int choices[MAXK];
    Student() {}
    bool operator<(const Student& s) const {  // 按总成绩从大到小排名，总成绩一样的，再按 GE 从大到小排名
        if (grade != s.grade) {
            return grade > s.grade;
        }
        return GE > s.GE;
    }
};

Student stus[MAXN];
int quotas[2][MAXM];   // 每所学校的限额和当前录取到的学生最后排名
priority_queue<int, vector<int>, greater<int> > admissions[MAXM];  // 每所学校最终录取的学生编号，用优先队列方便按编号从小到大输出

// 确定学生的排名
void Rank(int n) {
    sort(stus, stus + n);
    int preGrade = -1, preGE = -1, rank = 0;
    for (int i = 0; i < n; i++) {
        // 如果当前学生的总成绩和 GE 分别和上一个学生的总成绩和 GE 相同，则两人排名相同
        if (stus[i].grade == preGrade && stus[i].GE == preGE) {
            stus[i].rank = rank;
        } else {
            stus[i].rank = ++rank;
            preGrade = stus[i].grade;
            preGE = stus[i].GE;
        }
    }
}

// 执行录取规则
void proceedAdmission(int n, int k) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            int choice = stus[i].choices[j];
            // 如果当前学生的志愿学校录取名额没满，或者虽然满了但学生排名和该学校最后排名一样的话，执行录取
            if (admissions[choice].size() < quotas[0][choice] || stus[i].rank == quotas[1][choice]) {
                admissions[choice].push(stus[i].number);
                quotas[1][choice] = stus[i].rank;
                break;
            }
        }
    }
}

void OutputAdmission(int m) {
    for (int i = 0; i < m; i++) {
        bool first = true;
        while (!admissions[i].empty()) {    // 每次输出都会将优先队列排空，故也不会影响下组样例
            if (first) {
                printf("%d", admissions[i].top());
                first = false;
            } else {
                printf(" %d", admissions[i].top());
            }
            admissions[i].pop();
        }
        printf("\n");
    }
}

int main() {
    int n, m, k;
    while (scanf("%d %d %d", &n, &m, &k) != EOF) {
        for (int i = 0; i < m; i++) {
            scanf("%d", &quotas[0][i]);
        }
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &stus[i].GE, &stus[i].GI);
            for (int j = 0; j < k; j++) {
                scanf("%d", &stus[i].choices[j]);
            }
            stus[i].number = i;
            stus[i].grade = stus[i].GE + stus[i].GI; // 不要除以 2，避免精度问题
        }
        Rank(n);
        proceedAdmission(n, k);
        OutputAdmission(m);
    }
    return 0;
}
