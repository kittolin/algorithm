/*
* 名称：Hello World for U
* 来源：浙江大学复试上机题
* 链接：http://985.so/k2ar
* 难度：简单
*/

#include <iostream>
#include <string>

using namespace std;

void PrintSharpU(string str) {
    int n1 = (str.size() + 2) / 3;    // U 左竖边的长度
    int spaces = str.size() - 2 * n1; // 除最后一行外，其他行需要补充的空格数
    int head = 0, tail = str.size() - 1;
    while(head < n1 - 1) {
        printf("%c", str[head++]);
        int i = spaces;
        while (i --) {
            printf(" ");
        }
        printf("%c\n", str[tail--]);
    }

    // 打印最后一行
    while(head <= tail) {
        printf("%c", str[head++]);
    }
    printf("\n");
}

int main() {
    string str;
    while (cin >> str) {
        PrintSharpU(str);
    }
    return 0;
}
