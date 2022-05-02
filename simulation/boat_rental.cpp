/*
* 名称：游船出租
* 来源：浙江大学复试上机题
* 链接：http://985.so/k1zh
* 难度：较难
*/

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

const int MAXN = 100 + 10;
int boatsTime[MAXN];    // 记录每只船的出租开始时间，用 -1 表示还没出租
int rentalCount;              // 当天的游客租船次数
int totalTime;          // 出租的总时间

void Initial() {
    rentalCount = 0;
    totalTime = 0;
    fill(boatsTime, boatsTime + MAXN, -1);
}

// 将字符串的时间转换成分钟数
int Time2Minutes(string time) {
    return stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2));
}

int main() {
    Initial();
    int boat;
    char key;
    string time;
    while (cin >> boat >> key >> time) {
        if (boat == -1) {
            break;
        }
        if (boat == 0) {
            if (rentalCount == 0) {
                cout << 0 << ' ' << 0 << endl;
            } else {
                cout << rentalCount << ' ' << round(totalTime * 1.0 / rentalCount) << endl;
            }
            Initial();  // 一天租船工作结束，重新初始化
        }

        // 在还船时再进行数据统计，避免了只有租船记录没有还船记录的错误统计
        // 还船时，boatsTime 元素为 -1，表明先前没有租船记录，则直接跳过
        if (key == 'S') {
            boatsTime[boat] = Time2Minutes(time);
        } else if (boatsTime[boat] != -1) {
            rentalCount ++;
            totalTime += Time2Minutes(time) - boatsTime[boat];
        }
    }
    return 0;
}
