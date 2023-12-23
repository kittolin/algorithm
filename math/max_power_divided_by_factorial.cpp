/*
* 题目：整除问题

* 链接：http://985.so/xw1t
* 难度：中等
* 分析：暴力求 n 的阶乘会超时，且数字非常大，不可行。将 a 拆分成多个质因子 的乘积，2 ~ n 所有整数的质因子能组成多少组 a 的质因子组，即为所求的 k
*/

#include <iostream>
#include <cstdio>
#include <unordered_map>
#include <vector>
#include <cstring>
#include <climits>

using namespace std;

const int MAXN = 1000 + 10;
const int MAX_PRIME = 40;   // sqrt(MAXN)，因为任何正整数 n 最多只会有一个大于 sqrt(n) 的质因子
const int INF = INT_MAX;

bool isPrime[MAX_PRIME];
vector<int> primes;
int pFactorCount[MAXN];             // 2~n 所有整数的质因子计数
unordered_map<int, int> pFactors;   // a 的质因子计数

// 质数筛法
void PrimesSieve() {
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i < MAX_PRIME; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (int j = i * i; j < MAX_PRIME; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

// 短除法
void PrimeFactorCount(int number, bool toArray) {
    for (int i = 0; i < primes.size(); i++) {
        while (number % primes[i] == 0) {
            toArray? pFactorCount[primes[i]]++ : pFactors[primes[i]]++;
            number /= primes[i];
        }
        if (number == 1) {
            break;
        }
    }
    if (number > 1) {   // number 有大于 sqrt(number) 的质因子
        toArray? pFactorCount[number]++ : pFactors[number]++;
    }
}

int MaxPowerDividedByFactorial(int n, int a) {
    memset(pFactorCount, 0, sizeof(pFactorCount));
    for (int i = 2; i <= n; i++) {
        PrimeFactorCount(i, true);
    }
    PrimeFactorCount(a, false);

    int maxPower = INF;
    for (auto& pair: pFactors) {
        maxPower = min(maxPower, pFactorCount[pair.first] / pair.second);   // eg: a = 12 = 2 * 2 * 3
    }
    return maxPower;
}

// int MaxPowerDividedByFactorial(int n, int a) {
//     long long factorial = 1;
//     for (int i = 2; i <= n; i++) {
//         factorial *= i;
//     }

//     int k = 0;
//     while (factorial % a == 0) {
//         k++;
//         factorial /= a;
//     }
//     return k;
// }

int main() {
    PrimesSieve();
    int n, a;
    scanf("%d %d", &n, &a);
    printf("%d\n", MaxPowerDividedByFactorial(n, a));
}
