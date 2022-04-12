/*
* 名称：质因子的个数
* 来源：清华大学复试上机题
* 链接：http://t.cn/Aip7J0Oo
* 难度：较难
* 算法：短除法
*/

#include <iostream>
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
int NumOfPrimeFactors(int n) {
    int num = 0;
    for (int i = 0; i < primes.size(); i++) {
        int e = 0;
        // 累加各个质因子的指数
        while (n % primes[i] == 0) {
            n /= primes[i];
            e ++;
        }
        num += e;

        // 没有大于 sqrt(n) 的质因子，分解到 1 结束
        if (n == 1) {
            break;
        }
    }

    // 有大于 sqrt(n) 的质因子
    if (n > 1) {
        num ++;
    }

    return num;
}

// 直接短除法，不用先记录质数
int NumOfPrimeFactors2(int n) {
    int num = 0;
    for (int i = 2; i * i <= n; i++) {
        // i 为合数时不会进入 while 循环，因为合数已经被前面的质因子除尽了
        while (n % i == 0) {
            n /= i;
            num ++;
        }
        if (n == 1) {
            break;
        }
    }
    if (n > 1) {
        num ++;
    }
    return num;
}

int main() {
    // Initial();
    int n;
    while (scanf("%d", &n) != EOF) {
        printf("%d\n", NumOfPrimeFactors2(n));
    }
    return 0;
}
