/*
* 名称：鸡兔同笼 - 最少和最多
* 来源：北京大学复试上机题
* 链接：http://985.so/kg6c
* 难度：中等
*/

#include <cstdio>

using namespace std;

int main() {
    int feet, least, most;
    while (scanf("%d", &feet) != EOF) {
        if (feet % 2) {  // 不可能出现脚的总数为奇数的情况
            least = 0;
            most = 0;
        } else {
            least = feet / 4 + feet % 4 / 2; // 全部都是兔子或者只有一个鸡的情况下最少
            most = feet / 2;    // 全部都是鸡的情况下最多
        }
        printf("%d %d\n", least, most);
    }
    return 0;
}
