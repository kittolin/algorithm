/*
* 名称：Counterfeit Dollar
* 来源：北京大学复试上机题
* 链接：http://985.so/aemd
* 难度：较难
* 分析：有 12 个硬币，11 真 1 假，假币轻重未知，给出三次称量结果。
*       (1) 如果结果为 even，则左右两边均为真币；
*       (2) 如果结果为 up，即左边大于右边，则假币轻的情况下左边和未称的为真，假币重的情况下右边和未称的为真
*       (3) 如果结果为 down，即左边小于右边，则假币轻的情况下右边和未称的为真，假币重的情况下左边和未称的为真
*     最终 light 和 heavy 数组中必有一个硬币的真假相反，该币即为假币
*/

// #include <iostream>
// #include <string>
// #include <cstring>

// using namespace std;

// bool isTrueDollar[12];

// void SetTrueInclude(string str) {
//     for (int i = 0; i < str.size(); i++) {
//         isTrueDollar[str[i] - 'A'] = true;
//     }
// }

// int CounterfeitDollar(string str) {
//     for (int i = 0; i < str.size(); i++) {
//         if (!isTrueDollar[str[i] - 'A']) {
//             return str[i] - 'A';
//         }
//     }
//     return -1;
// }

// int main() {
//     string left, right, result, cLeft, cRight, cResult;
//     int count = -1;
//     while (cin >> left >> right >> result) {
//         count = (count + 1) % 3;
//         if (count == 0) {
//             memset(isTrueDollar, false, sizeof(isTrueDollar));
//         }

//         if (result == "even") {
//             SetTrueInclude(left);
//             SetTrueInclude(right);
//         } else {
//             cLeft = left;
//             cRight = right;
//             cResult = result;
//         }

//         if (count == 2) {
//             char counterfeit;
//             string weight;
//             if (CounterfeitDollar(cLeft) != -1) {
//                 counterfeit = CounterfeitDollar(cLeft) + 'A';
//                 weight = cResult == "up"? "heavy": "light";
//             } else {
//                 counterfeit = CounterfeitDollar(cRight) + 'A';
//                 weight = cResult == "up"? "light": "heavy";
//             }
//             cout << counterfeit << " is the counterfeit coin and it is " << weight << "." << endl;
//         }
//     }
//     return 0;
// }

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

const int MAXN = 12;

bool fakeLight[MAXN];  // 假设假币较轻的情况下，标记每个币的真假，用下标 0-11 分别对应 A-L
bool fakeHeavy[MAXN];  // 假设假币较重的情况下，标记每个币的真假

// 将 str 中的每个币置为真
void SetTrueInclude(string str, string assumption) {
    for (int i = 0; i < str.size(); i++) {
        if (assumption == "light") {
            fakeLight[str[i] - 'A'] = true;
        } else {
            fakeHeavy[str[i] - 'A'] = true;
        }
    }
}

// 将除 str 外的每个币置为真
void SetTrueExclude(string str, string assumption) {
    for (int i = 0; i < MAXN; i++) {
        if (str.find('A' + i) == str.npos) {
            if (assumption == "light") {
                fakeLight[i] = true;
            } else {
                fakeHeavy[i] = true;
            }
        }
    }
}

void SetTrueDollar(string left, string right, string result) {
    if (result == "up") {
        SetTrueInclude(left, "light");   // 假设假币较轻的情况下，左边都是真币，右边存在假币，除右边外的每个币都是真币
        SetTrueExclude(right, "light");
        SetTrueInclude(right, "heavy"); // 假设假币重，左假右真
        SetTrueExclude(left, "heave");
    } else if (result == "down") {
        SetTrueInclude(right, "light");  // 假设假币轻，左假右真
        SetTrueExclude(left, "light");
        SetTrueInclude(left, "heavy");  // 假设假币重，左真右假
        SetTrueExclude(right, "heavy");
    } else {  // even
        SetTrueInclude(left, "light");
        SetTrueInclude(right, "light");
        SetTrueInclude(left, "heavy");
        SetTrueInclude(right, "heavy");
    }
}

int main() {
    string left, right, result;
    int count = -1;  // 用于计数，每输入三次输出一次结果
    while (cin >> left >> right >> result) {
        count = (count + 1) % 3;
        if (count == 0) {
            memset(fakeLight, false, sizeof(fakeLight));
            memset(fakeHeavy, false, sizeof(fakeHeavy));
        }

        SetTrueDollar(left, right, result);
    
        if (count == 2) {
            char fake;
            string weight;
            for (int i = 0; i < MAXN; i++) {
                // 只有假币在两数组中的真假不一样，根据哪个数组中的值为 false 来判断假币的轻重
                if (fakeLight[i] != fakeHeavy[i]) {
                    fake = 'A' + i;
                    weight = fakeLight[i] == false? "light": "heavy";
                    break;
                }
            }
            cout << fake << " is the counterfeit coin and it is " << weight << "." << endl;
        }
    }
    return 0;
}
