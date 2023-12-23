/*
* 名称：计算表达式

* 链接：http://985.so/9zre
* 难度：中等
*/

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int Priority(char c) {
    if (c == '#') {
        return 0;
    }
    if (c == '$') {
        return 1;
    }
    if (c == '+' || c == '-') {
        return 2;
    }
    return 3;
}

int GetNumber(string expression, int& index) {  // !!! index 需传递引用类型
    int number = 0;
    while (isdigit(expression[index])) {
        number = number * 10 + expression[index] - '0';
        index ++;
    }
    return number;
}

double Operation(double x, double y, char c) {
    if (c == '+') {
        return x + y;
    }
    if (c == '-') {
        return x - y;
    }
    if (c == '*') {
        return x * y;
    }
    return x / y;
}

double Calculation(string expression) {
    stack<double> numbers;  // 数字栈
    stack<char> operators;  // 运算符栈
    operators.push('#');
    expression += '$';
    int index = 0;

    while (index < expression.size()) {
        if (isdigit(expression[index])) {
            numbers.push(GetNumber(expression, index));
        } else if (Priority(operators.top()) < Priority(expression[index])) {
            operators.push(expression[index]);
            index ++;
        } else {  // 这里 index 不能加 1，因为要循环多次弹出运算符栈中大于等于当前遍历运算符的
            double y = numbers.top();
            numbers.pop();
            double x = numbers.top();
            numbers.pop();
            numbers.push(Operation(x, y, operators.top()));
            operators.pop();
        }
    }
    return numbers.top();
}

int main() {
    string expression;
    while (cin >> expression) {
        printf("%.0f\n", Calculation(expression));
    }
    return 0;
}
