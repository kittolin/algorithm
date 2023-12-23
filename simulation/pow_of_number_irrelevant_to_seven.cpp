/*
* 名称：与 7 无关的数

* 链接：http://985.so/k44a
* 难度：中等
*/

#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 100;
vector<int> numbers;

bool Relevant2Seven(int number) {
    if (number % 7 == 0) {
        return true;
    }
    while (number) {
        if (number % 10 == 7) {
            return true;
        }
        number /= 10;
    }
    return false;
}

void Initial() {
    for (int i = 1; i <= MAXN; i++) {
        if (!Relevant2Seven(i)) {
            numbers.push_back(i);
        }
    }
}

int main() {
    Initial();
    int n;
    while (scanf("%d", &n) != EOF) {
        int sum = 0;
        for (int i = 0; i < numbers.size(); i++) {
            if (numbers[i] <= n) {
                sum += numbers[i] * numbers[i];
            } else {
                break;
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}
