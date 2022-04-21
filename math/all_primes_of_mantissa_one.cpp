/*
* 名称：小于 N 的所有尾数为 1 的素数
* 来源：北京航天航空大学复试上机题
* 链接：http://985.so/9shn
* 难度：较难
* 算法：求多个素数，用素数筛法
*/

#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

const int MAXN = 10000 + 10;

bool isPrime[MAXN];
vector<int> primes;  // 尾数为 1 的素数

void PrimeSieve() {
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = isPrime[1] =false;
    for (int i = 2; i < MAXN; i++) {
        if (!isPrime[i]) {
            continue;
        }
        if (i % 10 == 1) {
            primes.push_back(i);
        }

        if (i > MAXN / i) {  // i*i > MAXN 时不会进入下面的循环，但 i*i 可能会导致 int 溢出
            continue;        // 不能用 break，否则会导致如 661 等素数无法进入 primes 数组
        }
        for (int j = i * i; j < MAXN; j += i) {
            isPrime[j] = false;
        }
    }
}

int main() {
    PrimeSieve();
    int n;
    while (scanf("%d", &n) != EOF) {
        if (n <= primes[0]) {
            printf("%d\n", -1);
            continue;
        }
        for (int i = 0; i < primes.size(); i++) {
            if (n <= primes[i]) {
                break;
            }
            if (i == 0) {
                printf("%d", primes[i]);
            } else {
                printf(" %d", primes[i]);
            }
        }
        printf("\n");
    }
    return 0;
}
