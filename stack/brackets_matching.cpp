/*
* 名称：扩号匹配问题

* 链接：http://ccnu.openjudge.cn/practice/1978/
* 算法：遍历字符串，遇到左括号入栈，遇到右括号出栈。若出栈时栈为空，则右括号失配；若遍历完成后栈不为空，则栈中的左括号失配。
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <stack>

using namespace std;

string BracketsMatching(string str) {
    string ans(str.size(), ' ');
    stack<int> brackets;   // 存储左括号的下标

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(') {
            brackets.push(i);
        }
        if (str[i] == ')') {
            if (brackets.empty()) {  // 右括号失配
                ans[i] = '?';
            } else {
                brackets.pop();     // 左右括号匹配
            }
        }
    }
    while (!brackets.empty()) {
        ans[brackets.top()] = '$';  // 左括号失配
        brackets.pop();
    }

    return ans;
}

int main() {
    string str;
    while (cin >> str) {
        cout << str << endl;
        cout << BracketsMatching(str) << endl;
    }
}
