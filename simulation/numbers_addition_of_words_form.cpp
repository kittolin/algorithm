/*
* 名称：英文单词表示的数字加法
* 来源：浙江大学复试上机题
* 链接：http://985.so/kmeq
* 难度：中等
* 算法：遍历表达式，遇到空格，则提取前面的数位；遇到加号，则将前面的数位组成被加数；遇到等号，则将前面的数位组成加数。
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<string, int> map;

void Initial() {
    string words[10] = {
        "zero", "one", "two", "three", "four",
        "five", "six", "seven", "eight", "nine"
    };
    for (int i = 0; i < 10; i++) {
        map[words[i]] = i;
    }
}

vector<int> GetAddends(string expr) {
    vector<int> addends;
    int addend = 0, head = 0, tail = 0;
    while (tail < expr.size()) {
        if (expr[tail] == ' ') {
            addend = addend * 10 + map[expr.substr(head, tail - head)]; // 提取数位
            while (expr[++tail] == ' ');  // 如果有多个空格，跳过
            head = tail;
        } else if (expr[tail] == '+') {
            addends.push_back(addend);    // 组成被加数  
            addend = 0;
            while (expr[++tail] == ' ');
            head = tail;
        } else if (expr[tail] == '=') {
            addends.push_back(addend);    // 组成加数
            tail ++;
        } else {
            tail ++;
        }
    }
    return addends;
}

int main() {
    Initial();
    string expr;
    while (getline(cin, expr)) {
        vector<int> addends = GetAddends(expr);
        if (addends[0] == 0 && addends[1] == 0) {
            break;
        }
        cout << addends[0] + addends[1] << endl;
    }
    return 0;
}
