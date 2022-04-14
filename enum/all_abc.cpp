/*
* 名称：abc
* 来源：清华大学复试上机题
* 链接：http://t.cn/E9WMRTE
* 难度：入门
* 分析：采用穷举的话时间复杂度为 O(n ^ 3)，可以支持的数据量为 200，本题的 n 为 10，满足条件
*/

#include <iostream>
#include <cstdio>

using namespace std;

const int NUM = 532;

int main() {
    for (int a = 0; a < 10; a++) {
        for (int b = 0; b < 10; b ++) {
            for (int c = 0; c < 10; c++) {
                // abc + bcc = (100a + 10b + c) + (100b + 10c + c) = 100a + 110b + 12c
                if (a * 100 + b * 110 + c * 12 == NUM) {
                    printf("%d %d %d\n", a, b, c);
                }
            } 
        }
    }
    return 0;
}
