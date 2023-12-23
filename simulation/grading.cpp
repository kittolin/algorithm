/*
* 名称：Grading

* 链接：http://985.so/k0ag
* 难度：中等
*/

#include <cstdio>
#include <iostream>

using namespace std;

int Abs(int num) {
    return num >= 0? num: -num;
}

double FinalGrade(int T, int G1, int G2, int G3, int GJ) {
    if (Abs(G1 - G2) <= T) {
        return (G1 + G2) / 2.0; 
    }
    if (Abs(G3 - G1) <= T && Abs(G3 - G2) <= T) {
        return max(G1, G2, G3);
    }
    if (Abs(G3 - G1) <= T) {
        return (G1 + G3) / 2.0;
    }
    if (Abs(G3 - G2) <= T) {
        return (G2 + G3) / 2.0;
    }
    return GJ;
}

int main() {
    int P, T, G1, G2, G3, GJ;
    while (scanf("%d %d %d %d %d %d", &P, &T, &G1, &G2, &G3, &GJ) != EOF) {
        printf("%.1f\n", FinalGrade(T, G1, G2, G3, GJ));
    }
}
