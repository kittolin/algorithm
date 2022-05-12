/*
* 名称：一个数的二进制表示能否通过循环左移得到另一个数的二进制表示
* 来源：北京大学复试上机题
* 链接：http://985.so/xtuc
* 难度：简单
* 分析：如果第二个数不能通过循环左移得到第一个数，那么第一个数也肯定不能通过循环左移得到第二个数。故只需判断一种情况即可。
*/

#include <cstdio>
#include <iostream>

using namespace std;

/*
* #1 将整数转换成二进制表示，通过双指针逐位比较
*/
// const int DIGITS = 16;

// char arr1[DIGITS];
// char arr2[DIGITS];

// void ConvertToBinary(int number, bool toArr1) {
//     if (toArr1) {
//         fill(arr1, arr1 + DIGITS, '0');
//     } else {
//         fill(arr2, arr2 + DIGITS, '0');
//     }

//     int index = DIGITS - 1;
//     while (number) {
//         if (toArr1) {
//             arr1[index--] = number % 2 + '0';
//         } else {
//             arr2[index--] = number % 2 + '0';
//         }
//         number /= 2;
//     }
// }

// // 第一个数从 i=0 开始，第二个数从 j=index 开始，逐位比较是否都相同
// bool AllSameDigits(int index) {
//     int i = 0, j = index;
//     while (i < DIGITS) {
//         // 只要有一位不相同就不用比较了
//         if (arr1[i] != arr2[j]) {
//             return false;
//         }
//         i ++;
//         j = (j + 1) % DIGITS;
//     }
//     return true;
// }

// // 第二个数的二进制能否通过循环左移得到第一个数的二进制
// bool IfRotateLeftTo() {
//     // 最多需要 16 次判断
//     for (int j = 0; j < DIGITS; j++) {
//         if (AllSameDigits(j)) {
//             return true;
//         }
//     }
//     return false;
// }

// int main() {
//     int num1, num2;
//     while (scanf("%d %d", &num1, &num2) != EOF) {
//         ConvertToBinary(num1, true);
//         ConvertToBinary(num2, false);
//         if (IfRotateLeftTo()) {
//             printf("YES\n");
//         } else {
//             printf("NO\n");
//         }
//     }
//     return 0;
// }

/*
* #2 位运算实现 num2 循环左移：num2 左移，再加上最高的移出位，最后取低 16 位
*/

const int DIGITS = 16;
const int MASK = 0xffff;  // 用于取低 16 位

// num2 能否通过循环左移得到 num1
bool IfRotateLeftTo(int num1, int num2) {
    // 最多需要 16 次判断
    for (int i = 0; i < DIGITS; i++) {
        if (num1 == num2) {
            return true;
        }
        int highest = num2 >> (DIGITS - 1);
        num2 = ((num2 << 1) + highest) & MASK;  // !!! 移位的优先级低于加法，需要加括号
    }
    return false;
}

int main() {
    int num1, num2;
    while (scanf("%d %d", &num1, &num2) != EOF) {
        if (IfRotateLeftTo(num1, num2)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}
