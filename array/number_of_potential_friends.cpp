/*
* 名称：谁是你的潜在朋友

* 链接：http://985.so/k4f8
* 难度：中等
*/

#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 200 + 10;
const int MAXM = 200 + 10;

int bookOfReader[MAXN];     // 每个读者喜欢的图书编号
int readersOfBook[MAXM];    // 每一本图书被多少读者喜欢

int main() {
    int n, m, bookNumber;
    while (scanf("%d %d", &n, &m) != EOF) {
        memset(readersOfBook, 0, sizeof(readersOfBook));
        for (int i = 1; i <= n; i++) {
            scanf("%d", &bookNumber);
            bookOfReader[i] = bookNumber;
            readersOfBook[bookNumber] ++;
        }
        for (int i = 1; i <= n; i++) {
            if (readersOfBook[bookOfReader[i]] > 1) {
                printf("%d\n", readersOfBook[bookOfReader[i]] - 1);
            } else {
                printf("BeiJu\n");
            }
        }
    }
    return 0;
}
