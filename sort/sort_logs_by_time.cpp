#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

/*
* #1 在排序时再使用双指针法拆分字符串得到各个字段，性能太差 
*/
// const int MAXN = 10000 + 10;
// string logs[MAXN];

// vector<string> SplitLog(string log) {
//     vector<string> vec;
//     int head = 0, tail = 0;
//     while (tail < log.size()) {
//         if (log[tail] == ' ') {
//             if (head < tail) {  // 预防 log 开头就是空格
//                 vec.push_back(log.substr(head, tail - head));
//             }
//             while (log[++tail] == ' '); // 跳过多个连续空格
//             head = tail;
//         } else if (log[tail] == '(') {
//             vec.push_back(log.substr(head, tail - head));
//             break;
//         } else {
//             tail ++;
//         }
//     }
//     return vec; 
// }

// bool Compare(string log1, string log2) {
//     vector<string> info1 = SplitLog(log1);
//     vector<string> info2 = SplitLog(log2);
//     if (info1[3] == info2[3]) {
//         return info1[1] + info1[2] < info2[1] + info2[2]; // 开始执行时间的格式固定，直接用字符串排序即可
//     }
//     return stof(info1[3]) < stof(info2[3]); // !!! 消耗时间的位数不确定，需要先转换成浮点数
// }
 
// int main() {
//     string log;
//     int total = 0;
//     while (getline(cin, log)) {
//         logs[total++] = log;
//     }
//     sort(logs, logs + total, Compare);
//     for (int i = 0; i < total; i++) {
//         cout << logs[i] << endl;
//     }
//     return 0;
// }

/*
* #2 在输入时使用 istringstream 函数进行字符串按空格拆分
*/

const int MAXN = 10000 + 10;

struct Log {
    string raw;  // 为了保证输出格式和输入时一致
    string date;
    string time;
    double cost;
};
Log arr[MAXN];

bool Compare(Log log1, Log log2) {
    if (log1.cost == log2.cost) {
        return log1.date + log1.time < log2.date + log2.time;
    }
    return log1.cost < log2.cost;
}

int main() {
    string log, tmp;
    int total = 0;
    while (getline(cin, log)) {
        istringstream stream(log);
        stream >> tmp;
        stream >> arr[total].date >> arr[total].time;
        stream >> tmp;
        arr[total].cost = stof(tmp.substr(0, tmp.find('(')));
        arr[total].raw = log;
        total ++;
    }
    sort(arr, arr + total, Compare);

    for (int i = 0; i < total; i++) {
        cout << arr[i].raw << endl;
    }
    return 0;
}
