/*
* 名称：字符串连接
* 来源：华中科技大学复试上机题
* 链接：http://985.so/9vui
* 难度：中等
*/

#include <cstdio>

using namespace std;

const int MAXN = 100 + 10;
char str1[MAXN * 2];
char str2[MAXN];

int main() {
    while (scanf("%s %s", &str1, & str2) != EOF) {
        int i = 0, j = 0;
        while (str1[i] != '\0') { // C 语言中的字符串以 '\0'结尾
            i ++;
        }
        while (str2[j] != '\0') {
            str1[i++] = str2[j++];
        }
        printf("%s\n", str1);     // printf 函数只会打印 '\0' 前面的字符
    }
    return 0;
}
