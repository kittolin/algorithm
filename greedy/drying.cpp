/*
* 名称：Drying
* 来源：北京大学 poj
* 链接：http://poj.org/problem?id=3104
* 算法：最小的烘干时间，最值问题转化为判定性问题
*      (1)判断时间 t 是否可行
*      (2)对时间 t 采用二分策略
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAXN = 1e5 + 10;
int water[MAXN];

// 用烘干能力为 k 的烘干机给 n 件衣服烘干，判断在时间 t 内能否完成
bool Judge(int n, int k, int t) {
    int sum = 0;
    for(int i = 0; i < n; i++) {
        // 只有含水量大于 t 才需要烘干机，!!! 烘干机比自然晾干每分钟多减少 k-1
        if (water[i] > t) {
            sum += ceil((water[i] - t) * 1.0 / (k - 1));
        }
        if (sum > t) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, k;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &water[i]);
    }
    scanf("%d", &k);
    sort(water, water + n);

    if (k == 1) {
        printf("%d", water[n - 1]);
    } else {
        int min = 1, max = water[n - 1];
        while (min <= max) {
            int mid = min + (max - min) / 2;
            if (Judge(n, k, mid)) {
                max = mid - 1;
            } else {
                min = mid + 1;
            }
        }
        printf("%d", min);
    }
    return 0;
}
