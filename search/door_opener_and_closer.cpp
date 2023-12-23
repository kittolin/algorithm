/*
* 名称：开门人和关门人

* 链接：http://985.so/k0z6
* 难度：中等
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
    int m;
    string number, checkIn, checkOut;
    while (cin >> m) {
        string opener = "", closer = "", earliestCheckIn = "23:59:59", latestCheckOut = "00:00:00";
        while (m --) {
            cin >> number >> checkIn >> checkOut;
            if (checkIn <= earliestCheckIn) {
                opener = number;
                earliestCheckIn = checkIn;
            }
            if (checkOut >= latestCheckOut) {
                closer = number;
                latestCheckOut = checkOut;
            }
        }
        cout << opener << " " << closer << endl;
    }
    return 0;
}
