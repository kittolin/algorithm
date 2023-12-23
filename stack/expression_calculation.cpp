/*
* 名称：表达式求值

* 链接：http://t.cn/AiKoGS94
* 难度：较难
*/

#include <iostream>
#include <cstdio>
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

double Calculation(double x, double y, char operation) {
    if (operation == '+') {
        return x + y;
    }
    if (operation == '-') {
        return x - y;
    }
    if (operation == '*') {
        return x * y;
    }
    if (operation == '/') {
        return x / y;
    }
    return 0;
}

// 数字可能有多位，index 传递引用类型，用于修改其指向下一个非数字字符
double GetNumber(string expression, int& index) {
    double number = 0;
    while (isdigit(expression[index])) {
        number = number * 10 + (expression[index] - '0');
        index ++;
    }
    return number;
}

double ExpressionCalculation(string expression) {
    stack<char> operators;
    stack<double> numbers;
    operators.push('#');
    expression += '$';
    int index = 0;

    while (index < expression.size()) {
        if (expression[index] == ' ') {
            index ++;
            continue;
        }

        if (isdigit(expression[index])) {   // 遇到数字，则压入数字栈
            numbers.push(GetNumber(expression, index));
        } else if (Priority(expression[index]) > Priority(operators.top())) { // 遇到运算符，且其优先级 > 符号栈顶符号优先级，则压入符号栈
            operators.push(expression[index]);
            index ++;
        } else {    // 遇到运算符，且其优先级 <= 符号栈顶符号优先级，则进行弹栈计算，index 不改变，循环进行
            double y = numbers.top();
            numbers.pop();
            double x = numbers.top();
            numbers.pop();
            numbers.push(Calculation(x, y, operators.top()));
            operators.pop();
        }
    }

    //   $
    //   #           x.xx
    // operators    numbers
    return numbers.top();
}

int main() {
    string expression;
    while (getline(cin, expression)) {
        if (expression == "0") {
            break;
        }
        printf("%.2f\n", ExpressionCalculation(expression));
    }
    return 0;
}
