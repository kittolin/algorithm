/*
* 名称：Senior's Gun

* 链接：http://acm.hdu.edu.cn/showproblem.php?pid=5281
* 
* 算法：关键条件不用杀死所有的怪，所以用贪心算法
*      (1)子问题：每次只打一枪
*      (2)局部最优解：用最强的枪打最弱的怪
*      (3)所有奖金总和
*/

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1e5 + 10;
const int MAXM = 1e5 + 10;
long long guns[MAXN];
long long monsters[MAXM];

bool Compare(long long x, long long y) {
    return x > y;
}

long long Greedy(int n, int m) {
    sort(guns, guns + n, Compare);
    sort(monsters, monsters + m);

    long long bonus = 0;
    for(int i = 0; i < n && i < m; i++) {
        if (guns[i] > monsters[i]) {
            bonus += (guns[i] - monsters[i]);
        } else {
            break;  // 如果当前最强的枪都打不了最弱的怪，后面就无需判断了
        }
    }
    return bonus;
}

int main() {
    int t, n, m;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &n, &m);
        for(int i = 0; i < n; i++) {
            scanf("%lld", &guns[i]);
        }
        for(int i = 0; i < m; i++) {
            scanf("%lld", &monsters[i]);
        }
        printf("%lld\n", Greedy(n, m));
    }
    return 0;
}
