/*
* 名称：剩余的树

* 链接：http://985.so/kx2m
* 难度：中等
*/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

/*
* #1 暴力解法
* 缺点：需要额外的标记数组空间，需要对每一个区间进行逐一遍历标记
*/
// const int MAXL = 10000 + 10;
// bool hasTree[MAXL]; 

// int main() {
//     int l, m, start, end;
//     while (scanf("%d %d", &l, &m) != EOF) {
//         memset(hasTree, true, l + 1);
//         while (m --) {
//             scanf("%d %d", &start, &end);
//             for (int i = start; i <= end; i++) {
//                 hasTree[i] = false;
//             }
//         }
//         int remain = 0;
//         for (int i = 0; i <= l; i++) {
//             if (hasTree[i]) {
//                 remain ++;
//             }
//         }
//         printf("%d\n", remain);
//     }
//     return 0;
// }

/*
* #2 区间排序和合并
*/

const int MAXM = 100 + 10;

struct Interval {
    int start;
    int end;
    bool operator<(const Interval& i) const {
        return start < i.start;
    }
};

Interval intervals[MAXM];

int RemainTrees(int trees, int m) {
    sort(intervals, intervals + m); // 按 start 从小到大排序，方便后续区间合并
    int curStart = intervals[0].start;
    int curEnd = intervals[0].end;
    for (int i = 1; i < m; i++) {
        if (intervals[i].start <= curEnd) { // 区间重叠，则合并成更大的区间
            curEnd = max(curEnd, intervals[i].end);
        } else {    // 区间无重叠，则当前区间已经是最大能合并的区间了，可以减去
            trees -= (curEnd - curStart + 1);
            curStart = intervals[i].start;
            curEnd = intervals[i].end;
        }
    }
    trees -= (curEnd - curStart + 1);   // 减去最后一个区间（也包括 m=1 的情况）
    return trees;
}

int main() {
    int l, m;
    while (scanf("%d %d", &l, &m) != EOF) {
        for (int i = 0; i < m; i++) {
            scanf("%d %d", &intervals[i].start, &intervals[i].end);
        }
        printf("%d\n", RemainTrees(l + 1, m));
    }
    return 0;
}
