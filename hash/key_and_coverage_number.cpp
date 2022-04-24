/*
* 名称：考拉兹猜想 - 关键数和覆盖数
* 来源：浙江大学复试上机题
* 链接：http://985.so/k2kj
* 难度：简单
*/

#include <cstdio>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int n, number;
    while (scanf("%d", &n) != EOF) {
        if (n == 0) {
            break;
        }
        unordered_map<int, bool> coverages;  // 标记某个数是否为覆盖数
        vector<int> keys;   // 存放关键数
        while (n --) {
            scanf("%d", &number);
            if (!coverages[number]) {
                keys.push_back(number);
                while (number != 1) {
                    if (number % 2) {
                        number = (3 * number + 1) / 2;
                    } else {
                        number /= 2;
                    }
                    coverages[number] = true;
                }
            }
        }
        for (int i = keys.size() - 1; i >= 0; i--) {
            if (!coverages[keys[i]]) {  // 可能存在已存入 keys 的关键字被后面的关键字覆盖掉
                printf("%d ", keys[i]);
            }
        }
        printf("\n");
    }

    return 0;
}
