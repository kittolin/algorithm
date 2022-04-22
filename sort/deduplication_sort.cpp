/*
* 名称：排序且去重
* 来源：上海交通大学复试上机题
* 链接：http://985.so/9zeu
* 难度：中等
*/

#include <cstdio>
#include <unordered_map>
#include <cstdlib>

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

void QuickSort(int left, int right) {
    if (left >= right) {
        return;
    }

    int pos = Partition(left, right);
    QuickSort(left, pos - 1);
    QuickSort(pos + 1, right);
}

int main() {
    int n, number;
    while (scanf("%d", &n) != EOF) {
        unordered_map<int, bool> map;  // 对输入的数字进行去重
        int length = 0;  // 去重后数组的长度
        while (n --) {
            scanf("%d", &number);
            if (!map[number]) {
                arr[length++] = number;
                map[number] = true;
            }
        }

        QuickSort(0, length - 1);
        for (int i = 0; i < length; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    return 0;
}
