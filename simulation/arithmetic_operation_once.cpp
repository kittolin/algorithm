/*
* 名称：进行一次算术运算

* 链接：http://985.so/k4bm
* 难度：简单
*/

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int Operation(int a, int b, char c) {
    int result = 1;
    if (c == '+') {
        result = a + b;
    } else if (c == '-') {
        result = a - b;
    } else if (c == '*') {
        result = a * b;
    } else if (c == '/') {
        result = a / b;
    } else if (c == '%') {
        result = a % b;
    } else {
        for (int i = 2; i <= a; i++) {
            result *= i;
        }
    }
    return result;
}

int main() {
    string expr;
    int a, b;
    char c;
    while (getline(cin, expr)) {
        istringstream steam(expr);
        steam >> a >> c;
        if (c != '!') {
            steam >> b;
        }

        if ((c == '/' || c == '%') && b == 0) {
            printf("error\n");
        } else {
            printf("%d\n", Operation(a, b, c));
        }
    }
    return 0;
}
