/*
* 名称：Zero-complexity Transposition

* 链接：http://t.cn/AiKa20bt
* 难度：简单
*/

#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        stack<long long> s;
        while (n --) {
            long long a;
            scanf("%lld", &a);
            s.push(a);
        }
        while (!s.empty()) {
            printf("%lld ", s.top());
            s.pop();
        }
        printf("\n");
    }
    return 0;
}
