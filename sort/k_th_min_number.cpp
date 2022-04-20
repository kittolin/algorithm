/*
* 名称：查找第 K 小数
* 来源：北京邮电大学复试上机题
* 链接：http://985.so/9n1d
* 难度：较难
* 分析：注意同样大小的数字算一样大，故需要在输入时用 hash 排重
*/

#include <cstdio>
#include <cstdlib>
#include <unordered_map>

using namespace std;

const int MAXN = 1000 + 10;
int arr[MAXN];

int Partition(int left, int right) {
    int pivot = left + rand() % (right - left + 1);
    swap(arr[left], arr[pivot]);
    while (left < right) {
        while (left < right && arr[left] <= arr[right]) {
            right --;
        }
        swap(arr[left], arr[right]);
        while (left < right && arr[left] <= arr[right]) {
            left ++;
        }
        swap(arr[left], arr[right]);
    }
    return left;
}

int KthMinNum(int left, int right, int k) {
    int pos = Partition(left, right);
    if (pos > k) {
        return KthMinNum(left, pos - 1, k);
    } else if (pos < k) {
        return KthMinNum(pos + 1, right, k);
    } else {
        return arr[pos];
    }
}

int main() {
    int n, k, number;
    while (scanf("%d", &n) != EOF) {
        unordered_map<int, bool> map;
        int length = 0;
        while (n --) {
            scanf("%d", &number);
            if (!map[number]) {
                arr[length++] = number;
                map[number] = true;
            }
        }
        scanf("%d", &k);
        printf("%d\n", KthMinNum(0, length - 1, k - 1));
    }
    return 0;
}
