/*
* 名称：玛雅人的密码锁 (连续的 2012 解开密码)
* 来源：清华大学复试上机题
* 链接：http://985.so/x6pa
* 难度：中等
* 算法：BFS
*      (1)状态空间：(移位后的字符串 str, 移位次数 count)
*      (2)状态转移：交换相邻的字符
*      (3)起始状态：(str, 0)
*      (4)目标状态：(str_contained_2012, least_count)
*/

#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>

using namespace std;

struct State {
    string str;
    int count;
    State(string s, int c): str(s), count(c) {}
};

bool Valid(int n, string str) {
    // 字符串长度至少为 4，且同时包含 0,1,2 三种字符
    return n >= 4 && str.find('0') != str.npos && str.find('1') != str.npos && str.find('2') != str.npos;
}

int BFS(int n, string str) {
    unordered_map<string, bool> map; // 标记要检索的字符串是否已放入队列
    map[str] = true;
    queue<State> states;
    states.push(State(str, 0));      // 压入初始状态

    while (!states.empty()) {
        State cur = states.front();
        states.pop();
        if (cur.str.find("2012") != cur.str.npos) { // 找到目标状态
            return cur.count;
        }

        // 两两交换相邻的字符，压入之前未放入队列的字符串
        for (int i = 0; i < n - 1; i++) {
            State next = cur;
            next.count ++;
            swap(next.str[i], next.str[i + 1]);
            if (!map[next.str]) {
                map[next.str] = true;
                states.push(next);
            }
        }
    }
    return -1;
}

int main() {
    int n;
    string str;
    while (cin >> n >> str) {
        if (Valid(n, str)) {
            cout << BFS(n, str) << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}
