/*
* 名称：箱子打包
* 来源：华东师范 ACM
* 链接：https://acm.ecnu.edu.cn/problem/1045/
* 算法：关键条件，每个箱子最多包含两个物品
*      (1)子问题：每次只装一个箱子，要尽可能装得满
*      (2)局部最优解：选最大和最小的一起装箱，若溢出则只装最大的
*      (3)装箱的数目
*/

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1e5 +10;
int lens[MAXN];

int Greedy(int n, int l) {
    sort(lens, lens + n);

    int num = 0, left = 0, right = n - 1;
    while(left <= right) {
        if (lens[left] + lens[right] <= l) {  // 最大和最小的一起装箱
            left ++;
            right --;
        } else {                              // 最大的单独装箱
            right --;
        }
        num ++;
    }

    return num;
}

int main() {
    int n, l;
    scanf("%d%d", &n, &l);
    for(int i = 0; i < n; i++) {
        scanf("%d", &lens[i]);
    }

    printf("%d", Greedy(n, l));
    return 0;
}
