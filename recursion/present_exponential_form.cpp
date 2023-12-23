/*
* 名称：将正整数表示成 2的幂次方

* 链接：http://985.so/xxic
* 难度：简单
*/

#include <iostream>
#include <string>

using namespace std;

string ExponentialForm(int n) {
    if (n == 0) {
        return "(0)";
    }
    if (n == 1) {
        return "";
    }

    string form = "";
    int base = 0;
    while (n) {
        if (n % 2) {
            form = "2" + ExponentialForm(base) + "+" + form;
        }
        n /= 2;
        base ++;
    }
    return "(" + form.substr(0, form.size() - 1) + ")";  // 去掉最后的加号，并加上左右括号
}

int main() {
    int n;
    string form;
    while (cin >> n) {
        if (n == 1) {
            cout << "2(0)" << endl;
        } else {
            form = ExponentialForm(n);
            cout << form.substr(1, form.size() - 2) << endl;  // 去掉左右括号
        }
    }
    return 0;
}

