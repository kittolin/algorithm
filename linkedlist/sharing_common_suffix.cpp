/*
* 名称：Sharing Common Suffix
* 来源：浙江大学复试上机题
* 链接：http://985.so/k1rf
* 难度：中等
* 算法：统计各个节点 next 指针出现的次数，等于 2 的就是公共后缀开头
*/

#include <cstdio>
#include <unordered_map>

using namespace std;

int main() {
    int head1, head2, address, next, n;
    char data;
    while (scanf("%d %d %d", &head1, &head2, &n) != EOF) {
        unordered_map<int, int> map;
        while (n --) {
            scanf("%d %c %d", &address, &data, &next);
            map[next] ++;
        }

        int start = -1;
        for (auto& pair: map) {
            if (pair.second == 2) {
                start = pair.first;
            }
        }
        if (start == -1) {
            printf("%d\n", start);
        } else {
            printf("%05d\n", start);
        }
    }
    return 0;
}
