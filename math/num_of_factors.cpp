/*
* 名称：约数的个数

* 链接：http://985.so/wmy4
* 难度：较难
* 算法：短除法进行质因子分解，累乘 (e + 1)
*/

#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 4e4;  // n 最大为 1e9，n 最多只会有一个大于 sqrt(n) 的质因子，故记录到稍大于 sqrt(n) 的素数即可
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
        for (int j = i * i; j < MAXN; j+= i) {
            isPrime[j] = false;
        }
    }
}

// 质数筛法 + 短除法
int NumOfFactors(int n) {
    int num = 1;
    for (int i = 0; i < primes.size(); i++) {
        int e = 0;
        // 累乘各个质因子的指数
        while (n % primes[i] == 0) {
            n /= primes[i];
            e ++;
        }
        num *= (e + 1);

        // 没有大于 sqrt(n) 的质因子，分解到 1 结束
        if (n == 1) {
            break;
        }
    }

    // 有大于 sqrt(n) 的质因子
    if (n > 1) {
        num *= (1 + 1);
    }

    return num;
}

int main() {
    Initial();
    int n;
    while (scanf("%d", &n) != EOF) {
        while (n --) {
            int i;
            scanf("%d", &i);
            printf("%d\n", NumOfFactors(i));
        }
    }
    return 0;
}
