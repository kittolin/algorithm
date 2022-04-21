/*
* 名称：第 k 个素数
* 来源：上海交通大学复试上机题
* 链接：http://985.so/wmyk
* 难度：中等
* 算法：素数筛法
*/

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 1e5;  // k 最大为 1e4, MAXN 取 1e5 就足够了
vector<int> primes;
bool isPrime[MAXN];

void Initial() {
    fill(isPrime, isPrime + MAXN, true);  // isPrime 数组初始为 true
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i < MAXN; i++) {
        if (!isPrime[i]) {
            continue;
        }
        primes.push_back(i);

        // i*i > MAXN 时不会进入下面的循环，但 i*i 可能会导致 int 溢出
        if (i > MAXN / i) {
            continue;
        }
        // 从 i*i 开始，而不是 i+i，因为 i+i 在前面循环中已被标记为 false 了
        for (int j = i * i; j < MAXN; j += i) {
            isPrime[j] = false;
        }
    }
}

int main() {
    Initial();
    int k;
    while (scanf("%d", &k) != EOF) {
        printf("%d\n", primes[k - 1]);
    }
    return 0;
}
