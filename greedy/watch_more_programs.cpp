/*
* 名称：今年暑假不 AC

* 链接：http://acm.hdu.edu.cn/showproblem.php?pid=2037
* 分析：不能重叠的情况下最多的区间，选右端点最小
*      (1)开始时间最早 ❌
*           |------------------| 
*              |--| |--| |--|
*      (2)持续时间最短 ❌
*           |-------| |--------|
*                  |---|
*      (3)结束时间最早 ✅
* 算法：(1)每次只选一个节目
*      (2)选择结束时间最早的节目
*      (3)所有节目的数目
*/

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 100 + 10;

struct program {
    int startTime;
    int endTime;
};

program programs[MAXN];

// 结束时间越早的排在越前面
bool compare(program x, program y) {
    return x.endTime < y.endTime;
}

int greedy(int n) {
    sort(programs, programs + n, compare);
    int curTime = programs[0].endTime; // 看完第一个节目后的当前时间
    int count = 1;
    for (int i = 1; i < n; i++) {
        // 只有还没开始的节目才可以看
        if (programs[i].startTime >= curTime) {
            curTime = programs[i].endTime;
            count ++;
        }
    }
    return count;
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        if (n == 0) {
            break;
        }
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &programs[i].startTime, &programs[i].endTime);
        }
        printf("%d\n", greedy(n));
    }
    return 0;
}
