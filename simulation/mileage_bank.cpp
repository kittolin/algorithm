/*
* 名称：Mileage Bank
* 来源：北京大学复试上机题
* 链接：http://985.so/xctp
* 难度：中等
*/

#include <iostream>
#include <string>

using namespace std;

const double MIN_MILES = 500;

int Bonus(int miles, char code) {
    if (code == 'F') {
        return miles * 2;
    }
    if (code == 'B') {
        return miles + miles / 2;
    }
    if (miles < MIN_MILES) {
        return MIN_MILES;
    } else {
        return miles;
    }
}

int main() {
    string from, to;
    int miles, sum = 0;
    char code;
    while (cin >> from) {
        if (from == "#") {
            break;
        }
        if (from == "0") {
            printf("%d\n", sum);
            sum = 0;  // 清零进行下一轮计算
            continue;
        }

        cin >> to >> miles >> code;
        sum += Bonus(miles, code);
    }
    return 0;
}

