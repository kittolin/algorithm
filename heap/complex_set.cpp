/*
* 名称：复数集合

* 链接：http://t.cn/Ai98yYlt
* 难度：较难
*/

#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

struct Complex {
    int real;
    int imag;
    Complex(int r, int i): real(r), imag(i) {}
    bool operator<(Complex c) const {
        int modulus = real * real + imag * imag;
        int c_modulus = c.real * c.real + c.imag * c.imag;
        // 模值越大的优先级越大，模值相等的虚部越小的优先级越大
        if (modulus != c_modulus) {
            return modulus < c_modulus;
        }
        return imag > c.imag;
    }
};

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        priority_queue<Complex> pq;
        while (n --) {
            string command;
            cin >> command;

            if (command == "Insert") {
                int a, b;
                scanf("%d+i%d", &a, &b);
                pq.push(Complex(a, b));
                printf("SIZE = %d\n", pq.size());
            } else if (pq.empty()) {
                printf("empty\n");   
            } else {
                Complex c = pq.top();
                pq.pop();
                printf("%d+i%d\n", c.real, c.imag);
                printf("SIZE = %d\n", pq.size());
            }
        }
    }
    return 0;
}
