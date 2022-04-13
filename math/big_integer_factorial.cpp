/*
* 名称：N 的阶乘
* 来源：清华大学复试上机题
* 链接：http://t.cn/AipaBKQJ
* 难度：中等
*/

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 10000;

struct BigInteger {
    int digits[MAXN];                   // 用 int 不用 char，方便乘法计算
    int length;                         // 实际数位长度

    // 构造函数定义
    BigInteger();
    BigInteger(int x);
    BigInteger(string str);
    BigInteger(const BigInteger& b);    // 引用传递避免复制整个大数，const 保证不会修改 b

    // 赋值运算符重载
    BigInteger operator=(int x);
    BigInteger operator=(string str);
    BigInteger operator=(const BigInteger& b);

    // 比较运算符重载
    bool operator<(const BigInteger& b);
    bool operator<=(const BigInteger& b);
    bool operator==(const BigInteger& b);

    // 算术运算符重载
    BigInteger operator+(const BigInteger& b);
    BigInteger operator-(const BigInteger& b);
    BigInteger operator*(const BigInteger& b);
    BigInteger operator/(const BigInteger& b);
    BigInteger operator%(const BigInteger& b);

    // 输入输出运算符重载
    friend istream& operator>>(istream& in, BigInteger& b);
    friend ostream& operator<<(ostream& out, const BigInteger& b);
};

BigInteger::BigInteger() {
    memset(digits, 0, sizeof(digits));
    length = 0;
}

BigInteger::BigInteger(int x) {
    memset(digits, 0, sizeof(digits));
    length = 0;
    if (x == 0) {
        length ++;
    }
    while (x != 0) {
        digits[length ++] = x % 10;
        x /= 10;
    }
}

BigInteger::BigInteger(string str) {
    memset(digits, 0, sizeof(digits));
    length = str.size();
    for (int i = 0; i < length; i++) {
        digits[i] = str[length - 1 - i] - '0';  // 字符串需要逆序输入
    }
}

BigInteger::BigInteger(const BigInteger& b) {
    memset(digits, 0, sizeof(digits));
    length = b.length;
    for (int i = 0; i < length; i++) {
        digits[i] = b.digits[i];
    }
}

BigInteger BigInteger::operator=(int x) {
    memset(digits, 0, sizeof(digits));
    length = 0;
    if (x == 0) {
        length ++;
    }
    while (x != 0) {
        digits[length ++] = x % 10;
        x /= 10;
    }
    return *this;
}

BigInteger BigInteger::operator=(string str) {
    memset(digits, 0, sizeof(digits));
    length = str.size();
    for (int i = 0; i < length; i++) {
        digits[i] = str[length - 1 - i] - '0';  // 字符串需要逆序输入
    }
    return *this;
}

BigInteger BigInteger::operator=(const BigInteger& b) {
    memset(digits, 0, sizeof(digits));
    length = b.length;
    for (int i = 0; i < length; i++) {
        digits[i] = b.digits[i];
    }
    return *this;
}

// bool BigInteger::operator<(const BigInteger& b) {
//     if (length < b.length) {
//         return true;
//     } else if (b.length < length) {
//         return false;
//     } else {
//         for (int i = length - 1; i >= 0; --i) {
//             if (digits[i] == b.digits[i]) {
//                 continue;
//             } else {
//                 return digits[i] < b.digits[i];
//             }
//         }
//     }
//     return false;
// }

// bool BigInteger::operator<=(const BigInteger& b) {
//     if (length < b.length) {
//         return true;
//     } else if (b.length < length) {
//         return false;
//     } else {
//         for (int i = length - 1; i >= 0; --i) {
//             if (digits[i] == b.digits[i]) {
//                 continue;
//             } else {
//                 return digits[i] < b.digits[i];
//             }
//         }
//     }
//     return true;
// }

// bool BigInteger::operator==(const BigInteger& b) {
//     if (length != b.length) {
//         return false;
//     } else {
//         for (int i = length - 1; i >= 0; --i) {
//             if (digits[i] != b.digits[i]) {
//                 return false;
//             }
//         }
//     }
//     return true;
// }

BigInteger BigInteger::operator+(const BigInteger& b) {
    BigInteger ans;
    int carry = 0;
    for (int i = 0; i < length || i < b.length; i++) {  // 较小的数有前导 0，不用担心越界问题
        int sum = digits[i] + b.digits[i] + carry;
        ans.digits[ans.length ++] = sum % 10;
        carry = sum / 10;
    }

    // 最高位有进位
    if (carry != 0) {
        ans.digits[ans.length ++] = carry;
    }
    return ans;
}

// BigInteger BigInteger::operator-(const BigInteger& b) {
//     BigInteger answer;
//     int carry = 0;
//     for (int i = 0; i < length; ++i) {
//         int current = digits[i] - b.digits[i] - carry;
//         if (current < 0) {
//             current += 10;
//             carry = 1;
//         } else {
//             carry = 0;
//         }
//         answer.digits[answer.length++] = current;
//     }
//     while (answer.digits[answer.length - 1] == 0 && answer.length > 1)  {
//         answer.length--;
//     }
//     return answer;
// }

BigInteger BigInteger::operator*(const BigInteger& b) {
    BigInteger ans;
    ans.length = length + b.length;     // m 位数乘以 n 位数，结果最大只能是 (m+n) 位数

    //   b:     X X X
    // * a:       X X
    //----------------
    //          X X X
    // +      X X X
    //----------------
    // ans: X X X X X
    //
    // 先累加每一位的乘积，不管进位问题
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < b.length; j++) {
            ans.digits[i + j] += digits[i] * b.digits[j];
        }
    }

    // 处理进位问题
    for (int i = 0; i < ans.length; i++) {
        ans.digits[i + 1] += ans.digits[i] / 10;
        ans.digits[i] %= 10;
    }

    // 计算实际的乘积长度
    // 注意乘以 0 的情况，长度至少为 1
    while (ans.digits[ans.length - 1] == 0 && ans.length > 1) {
        ans.length --;
    }
    return ans;
}

// BigInteger BigInteger::operator/(const BigInteger& b) {
//     BigInteger answer;
//     answer.length = length;
//     BigInteger remainder = 0;
//     BigInteger temp = b;
//     for (int i = length - 1; i >= 0; --i) {
//         if (!(remainder.length == 1 && remainder.digits[0] == 0)) {
//             for (int j = remainder.length - 1; j >= 0; --j) {
//                 remainder.digits[j + 1] = remainder.digits[j];
//             }
//             remainder.length++;
//         }
//         remainder.digits[0] = digits[i];
//         while (temp <= remainder) {
//             remainder = remainder - temp;
//             answer.digits[i]++;
//         }
//     }
//     while (answer.digits[answer.length - 1] == 0 && answer.length > 1)  {
//         answer.length--;
//     }
//     return answer;
// }

// BigInteger BigInteger::operator%(const BigInteger& b) {
//     BigInteger remainder = 0;
//     BigInteger temp = b;
//     for (int i = length - 1; i >= 0; --i) {
//         if (!(remainder.length == 1 && remainder.digits[0] == 0)) {
//             for (int j = remainder.length - 1; j >= 0; --j) {
//                 remainder.digits[j + 1] = remainder.digits[j];
//             }
//             remainder.length++;
//         }
//         remainder.digits[0] = digits[i];
//         while (temp <= remainder) {
//             remainder = remainder - temp;
//         }
//     }
//     return remainder;
// }

istream& operator>>(istream& in, BigInteger& b) {
    string str;
    in >> str;
    b = str;
    return in;
}

ostream& operator<<(ostream& out, const BigInteger& b) {
    for (int i = b.length - 1; i >= 0; i--) {
        out << b.digits[i];
    }
    return out;
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        BigInteger ans(1);
        for (int i = 2; i <= n; i++) {
            ans = ans * BigInteger(i);
        }
        cout << ans << endl;
    }
    return 0; 
}
