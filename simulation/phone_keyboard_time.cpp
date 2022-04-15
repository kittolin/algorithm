/*
* 名称：手机键盘
* 来源：清华大学复试上机题
* 链接：http://t.cn/E9ulcIc
* 难度：中等
*/

#include <iostream>
#include <cstdio>

using namespace std;

// 每个字母需要按几次
int charsTime[26] = {
    1, 2, 3,    // ABC
    1, 2, 3,    // DEF
    1, 2, 3,    // GHI
    1, 2, 3,    // JKL
    1, 2, 3,    // MNO
    1, 2, 3, 4, // PQRS
    1, 2, 3,    // TUV
    1, 2, 3, 4  // WXYZ
};

int CharTime(char c) {
    return charsTime[c - 'a'];
}

int KeyboardTime(string input) {
    if (input == "") {
        return 0;
    }
    int time = CharTime(input[0]);
    for (int i = 1; i < input.size(); i++) {  // !!! 从 1 开始
        time += CharTime(input[i]);
        // 如果前后两字符的按键时间之差，刚好等于字符距离，说明在同一按键上
        int timeDiff = CharTime(input[i]) - CharTime(input[i - 1]);
        if (timeDiff == (input[i] - input[i - 1])) {
            time += 2;
        }
    }
    return time;
}

int main() {
    string input;
    while (cin >> input) {
        cout << KeyboardTime(input) << endl;
    }
    return 0;
}
