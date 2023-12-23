/*
* 名称：A ^ B 的最后三位整数

* 链接：http://acm.hdu.edu.cn/showproblem.php?pid=2035
* 
*/

#include <iostream>
#include <cstdio>

using namespace std;

int FastExponentiation(int a, int b, int mod) {
    int ans = 1;
    // b 不断右移取其二进制的每一位，若当前位为 1，则累乘 a 的 2^k 次幂
    while (b) {
        if (b % 2) {
            ans = (ans * a) % mod; // a 的 b 次幂可能会导致 int 溢出，所以在每次累乘后都先进行取模，不影响最终结果
        }
        a = (a * a) % mod;
        b /= 2;
    }
    return ans;
}

int main() {
    int a, b;
    while (scanf("%d %d", &a, &b) != EOF) {
        if (a == 0 && b == 0) {
            break;
        }
        printf("%d\n", FastExponentiation(a, b, 1000));
    }
    return 0;
}
