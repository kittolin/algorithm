/*
* 名称：最小年龄的三个职工
* 来源：华中科技大学复试上机题
* 链接：http://985.so/96db
* 难度：中等
*/

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Employee {
    int number;
    string name;
    int age;
    Employee(int n, string s, int a): number(n), name(s), age(a) {}
    bool operator<(const Employee& e) const {
        if (age != e.age) {
            return age < e.age;
        }
        if (number != e.number) {
            return number < e.number;
        }
        return name < e.name;
    }
};

int main() {
    int n;
    while (cin >> n) {
        priority_queue<Employee> pq;
        while (n --) {
            int number, age;
            string name;
            cin >> number >> name >> age;
            pq.push(Employee(number, name, age));
        }

        int count = 0;
        while (count < 3 && !pq.empty()) {
            Employee e = pq.top();
            pq.pop();
            count ++;
            cout << e.number << " " << e.name << " " << e.age << endl;
        }
    }
    return 0;
}
