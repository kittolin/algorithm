/*
* 名称：农夫、羊、菜和狼的故事

* 链接：http://985.so/ktu1
* 难度：中等
*
* 算法：最少的步骤，故采用 BFS
*      (1)状态空间：(标记数组 flags, 当前步骤 step, 过河过程 process)
*      (2)状态转移：flags 中和农夫在一起的可以随农夫过河(或者什么都不带)，step + 1， process += i(0, 1, 2, 3)
*      (3)起始状态：({X, 0, 0, 0}, 0, "")
*      (4)目标状态：({X, 1, 1, 1, Odd, "xxxxxxx"}
*
* 搜索树：
*                 ({0,0,0}, 0, "")
*                        /
*               ({0,1,0}, 1, "1")
*                     / \
*   ({0,1,0}, 2, "10")  ({0,0,0}, 2, "11") ......
*/

#include <iostream>
#include <string>
#include <queue>

using namespace std;

string map[4] = {"nothing", "vegetable", "sheep", "wolf"};

struct Status {
    bool flags[4];  // 下标 1, 2, 3 分别表示蔬菜，羊，狼，下标 0 冗余；false 表示在河这岸，true 表示过河对岸
    int step;       // 表当前第几步，为偶数时农夫在河这岸，为奇数时农夫过河对岸
    string process; // 过河步骤过程
    Status(bool f[3], int s, string p) {
        flags[0] = false;
        for (int i = 1; i <= 3; i++) {
            flags[i] = f[i - 1];
        }
        step = s;
        process = p;
    }
};

bool Valid(const Status& s) {
    bool f = s.step % 2 == 0;   // 偶数时农夫在河这岸，就检查河对岸；反之亦然
    // if (s.flags[1] == f && s.flags[2] == f) {   // 蔬菜和羊在一起
    //     return false;
    // }
    // if (s.flags[2] == f && s.flags[3] == f) {   // 羊和狼在一起
    //     return false;
    // }
    // return true;
    return !(s.flags[1] == f && s.flags[2] == f || s.flags[2] == f && s.flags[3] == f);
}

bool Succeed(const Status& s) {
    return s.flags[1] && s.flags[2] && s.flags[3];  // 蔬菜，羊和狼都到达河对岸
}

string BFS() {
    queue<Status> q;
    bool initFlags[3] = {false, false, false};
    q.push(Status(initFlags, 0, ""));   // 压入初始状态
    while (!q.empty()) {
        Status cur = q.front();
        q.pop();
        if (Succeed(cur)) {         // 找到了目标状态
            return cur.process;
        }

        for (int i = 0; i <= 3; i++) {
            Status next = cur;      // 每轮循环都创建一个新的 next，避免各个 next 数据互相影响
            next.step ++;
            next.process += (i + '0');      // 当前步骤带什么过河，0 表示什么都不带

            bool flag = next.step % 2 == 1;
            if (i != 0 && !next.flags[i] == flag) { // 如果当前步骤农夫要过河对岸，则只能带目前在河这岸的；反之亦然
                next.flags[i] = flag;
            }

            if (Valid(next)) {
                q.push(next);
            }
        }
    }
}

void PrintProcess(string process) {
    for (int i = 0; i < process.size(); i++) {
        if (i % 2) {
            cout << map[process[i] - '0'] << "_come" << endl;
        } else {
            cout << map[process[i] - '0'] << "_go" << endl;
        }
    }
    cout << "succeed" << endl;
}

int main() {
    string process = BFS();
    PrintProcess(process);
    return 0;
}
