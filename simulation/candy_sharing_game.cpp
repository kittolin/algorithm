/*
* 名称：Candy Sharing Game

* 链接：http://985.so/amd8
* 难度：较难
*/

#include <cstdio>

using namespace std;

const int MAXN = 1000 + 10;

int candyNum[MAXN];  // 记录每个学生的糖果数量

int GameRounds(int n) {
    int rounds = 0;
    while (1) {
        candyNum[0] = candyNum[n];  // 0 号位置用于每轮游戏时暂存最后一名学生的糖果数
        bool sameCandyNum = true;

        for (int i = n; i > 0; i--) {  // 因为是同时往右边给，所以必须是从后往前更新
            candyNum[i] = (candyNum[i] + 1) / 2 + candyNum[i - 1] / 2;  // 初始输入如果是奇数，则一半给右边，自己保留一半+1
            if (candyNum[i] % 2) {
                candyNum[i] ++;
            }
            if (sameCandyNum) {
                sameCandyNum = candyNum[i] == candyNum[n];  // !!! 因为是从后往前更新，故用最后一个学生的糖果数做判断
            }
        }
        rounds ++;

        if (sameCandyNum) {
            return rounds;
        }
    }
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        if (n == 0) {
            break;
        }

        bool sameCandyNum = true;
        for (int i = 1; i <= n; i++) {  // 逆时针输入
            scanf("%d", &candyNum[i]);
            if (sameCandyNum) {
                sameCandyNum = candyNum[i] == candyNum[1];
            }
        }

        if (sameCandyNum) {
            printf("%d %d\n", 0, candyNum[1]);
        } else {
            printf("%d %d\n", GameRounds(n), candyNum[1]);
        }
    }
    return 0;
}
