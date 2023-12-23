/*
* 名称：递推数列

* 链接：http://985.so/x6n0
* 难度：较难
*/

#include <cstdio>

using namespace std;

const int MOD = 10000;

int Recursion(int a0, int a1, int p, int q, int k) {
    if (k == 0) {
        return a0 % MOD;
    }
    if (k == 1) {
        return a1 % MOD;
    }

    int an;
    for (int i = 2; i <= k; i++) {
        an = (p * a1 + q * a0) % MOD;   // 不取模可能会导致整数溢出，最终结果只关心最后四位，故可以提前取模
        a0 = a1;
        a1 = an;
    }
    return an % MOD;
}

int main() {
    int a0, a1, p, q, k;
    scanf("%d %d %d %d %d", &a0, &a1, &p, &q, &k);
    printf("%d\n", Recursion(a0, a1, p, q, k));
    return 0;
}
