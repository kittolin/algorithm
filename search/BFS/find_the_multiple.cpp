/*
* 名称：Find The Multiple

* 链接：http://poj.org/problem?id=1426
*
* 算法：BFS
*      (1)状态空间：0, 1 构成的 number
*      (2)状态转移：(number * 10), (number * 10 + 1)
*      (3)起始状态：1
*      (4)目标状态：number % n == 0
*
* 搜索树：
*           1 
*         /   \
*      10      11
*      /\     / \
*   100 101 110 111
*
* 提交要用 G++，用 C++ 会超时
*/

#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

long long BFS(int n) {
    queue<long long> q;
    q.push(1);

    while (!q.empty()) {
        long long num = q.front();
        q.pop();
        if (num % n == 0) {
            return num;
        }
        q.push(num * 10);
        q.push(num * 10 + 1);
    }
    return 0;
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        if (n==0) {
            break;
        }
        printf("%lld\n", BFS(n));
    }
    return 0;
}
