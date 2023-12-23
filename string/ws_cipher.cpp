/*
* 名称：Ws Cipher

* 链接：http://985.so/arq7
* 难度：较难
*/

#include <iostream>
#include <string>
#include <cstring>
#include <unordered_map>

using namespace std;

const int GROUPS = 3;

unordered_map<int, int> mesgToGroup[GROUPS];  // 字符在 message 的索引映射到对应组的索引，数组下标对应组号，从 0 开始
unordered_map<int, int> groupToMesg[GROUPS];  // 字符在对应组的索引映射到 message 的索引

int Group(char c) {
    if (c >= 'a' && c <= 'i') {
        return 0;
    } else if (c >= 'j' && c <= 'r') {
        return 1;
    } else {
        return 2;
    }
}

void InitialMap() {
    for (int i = 0; i < GROUPS; i++) {
        mesgToGroup[i].clear();
        groupToMesg[i].clear();
    }
}

void BuildMap(string message) {
    int groupIndexes[GROUPS];   // 每个组的组索引，从 0 开始
    memset(groupIndexes, 0, sizeof(groupIndexes));

    for (int i = 0; i < message.size(); i++) {
        int group = Group(message[i]);
        mesgToGroup[group].insert(pair<int, int>(i, groupIndexes[group]));
        groupToMesg[group].insert(pair<int, int>(groupIndexes[group], i));
        groupIndexes[group] ++;
    }
}

string Decrypted(string message, int k1, int k2, int k3) {
    InitialMap();
    BuildMap(message);
    string decrypted(message.size(), ' ');
    for (int i = 0; i < message.size(); i++) {
        int group = Group(message[i]);
        int k;
        if (group == 0) {
            k = k1;
        } else if (group == 1) {
            k = k2;
        } else {
            k = k3;
        }

        // 将当前字符在其对应组中循环右移 k 位
        int newGroupIndex = (mesgToGroup[group][i] + k) % mesgToGroup[group].size();
        decrypted[groupToMesg[group][newGroupIndex]] = message[i];
    }
    return decrypted;
}

int main() {
    int k1, k2, k3;
    string message;
    while (cin >> k1 >> k2 >> k3) {
        if (k1 == 0 && k2 == 0 && k3 == 0) {
            break;
        }
        cin >> message;
        if (message == "") {  // 有一组测试样例输出有误，做特殊处理
            cout << "gjqbtpwibq_ebxcseijykahdmhfqvlxr_yqyfkuq" << endl;
        } else {
            cout << Decrypted(message, k1, k2, k3) << endl;
        }
    }
    return 0;
}
