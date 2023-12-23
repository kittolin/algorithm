/*
* 名称：输出梯形

* 描述：输入一个高度 h(1 <= h <= 1000)，输出一个高度为 h，上底边为 h 的梯形。
*/

#include <iostream>
#include <cstdio>

using namespace std;

// abase: 上底
// h: 高
// extra: 每行多几个字符
void OutputTrapezoid(int abase, int h, int extra, char c) {
    int ubase = abase + extra * (h - 1);    // 下底
    for (int i = 0; i < h; i++) {
        int ibase = abase + extra * i;
        for (int j = 0; j < ubase; j++) {
            if (j < ubase - ibase) {
                printf(" ");
            } else {
                printf("%c", c);
            }
        }
        printf("\n");
    }
}

int main() {
    int a, h, e;
    while (cin >> a >> h >> e) {
        OutputTrapezoid(a, h, e, '*');
    }
    return 0;
}
