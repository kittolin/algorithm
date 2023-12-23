/*
* 名称：排序

* 链接：http://t.cn/E9dLx5K
* 难度：较难
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int MAXN = 100 + 10;
int arr[MAXN];
int tmp[MAXN];

// 插入排序：每次将一个元素插入到前面已有序的子序列中
void InsertSort(int n) {
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) {      // 保证稳定性
            int temp = arr[i];          // 暂存，避免被覆盖
            int j;
            for (j = i - 1; j >= 0 && arr[j] > temp; j--) {
                arr[j + 1] = arr[j];    // 所有大于 temp 的都往后挪位
            }
            arr[j + 1] = temp;
        }
    }
}

// 希尔排序：先追求部分有序，再逐步逼近全局有序
// 将待排序表按增量 d 分成多个子表，对每个子表分别进行插入排序；缩小增量重复上述过程，直至 d = 1
void ShellSort(int n) {
    for (int d = n / 2; d >= 1; d /= 2) {
        for (int i = d + 1; i <= n; i++) {  // 每个子表轮流切换着排序
            if (arr[i] < arr[i - d]) {
                arr[0] = arr[i];            // arr[0] 不存储元素，不是哨兵，只是暂存单元
                // 插入到前面的有序增量子表
                int j;
                for (j = i - d; j > 0 && arr[j] > arr[0]; j -= d) {
                    arr[j + d] = arr[j];
                }
                arr[j + d] = arr[0];
            }
        }
    }
}

// 冒泡排序：每一趟排序将最小的元素冒到最前面
void BubbleSort(int n) {
    for (int i = 0; i < n - 1; i++) {   // 共 n-1 趟
        bool flag = false;
        for (int j = n - 1; j > i; j--) {
            if (arr[j - 1] > arr[j]) {  // 保证稳定性
                swap(arr[j - 1], arr[j]);
                flag = true;
            }
        }
        // 本趟排序如果没有发生交换，表明表已经有序
        if (!flag) {
            return;
        }
    }
}

int Partition(int left, int right) {
    int pivot = left + rand() % (right - left + 1); // 随机选择任一 left ~ right 中的元素作为 pivot
    swap(arr[left], arr[pivot]);                    // 将 pivot 元素放到序列最开始
    while (left < right) {                          // 当 left == right 时表示找到了最终的 pivot 位置
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

// 快速排序
void QuickSort(int left, int right) {
    if (left >= right) {  // Partition 可能返回 right，则进行下层递归时 left > right
        return;
    }
    int pos = Partition(left, right);
    QuickSort(left, pos - 1);
    QuickSort(pos + 1, right);
}

// 选择排序：每趟选择最小的元素加入前面的有序子序列
void SelectSort(int n) {
    for (int i = 0; i < n - 1; i++) {   // 无论有序、逆序、乱序，都需要 n-1 趟
        int min = i;    // 记录最小元素的位置
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        if (min != i) {
            swap(arr[min], arr[i]);     // 一次交换需要移动元素 3 次
        }
    }
}

// 调整以 k 为根的子树为大根堆
void HeadAdjust(int k, int len) {
    arr[0] = arr[k];    // arr[0] 暂存子树的根结点
    int i = k * 2;      // i 是 k 的左孩子
    while (i <= len) {
        if (i < len && arr[i] < arr[i + 1]) {   // 右孩子比左孩子更大
            i ++;
        }

        if (arr[0] >= arr[i]) { // 找到最终插入位置
            break;
        } else {
            arr[k] = arr[i];    // 孩子上浮
            k = i;
            i *= 2;
        }
    }
    arr[k] = arr[0];
}

// 建立大根堆
void BuildMaxHeap(int len) {
    // 堆本质是数组存储的完全二叉树，从索引 1 开始存储
    // 从后往前调整所有非终端结点
    for (int i = len / 2; i > 0; i--) {
        HeadAdjust(i, len);
    }
}

// 堆排序
void HeapSort(int len) {
    BuildMaxHeap(len);
    for (int i = len; i > 1; i--) { // 共 n-1 趟
        swap(arr[1], arr[i]);       // 交换堆顶和堆底元素
        HeadAdjust(1, i - 1);       // 将剩余的元素调整为大根堆
    }
}

void Combine(int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {  // <= 保证排序算法的稳定性
            tmp[k++] = arr[i++];
        } else {
            tmp[k++] = arr[j++];
        }
    }
    while(i <= mid) {
        tmp[k++] = arr[i++];
    }
    while(j <= right) {
        tmp[k++] = arr[j++];
    }

    // 复制回原数组
    for (k = left; k <= right; k++) {
        arr[k] = tmp[k];
    }
}

// 归并排序
void MergeSort(int left, int right) {
    // 只有一个元素，自然是有序的
    if (left == right) {
        return;
    }
    int mid = left + (right - left) / 2;
    MergeSort(left, mid);
    MergeSort(mid + 1, right);
    Combine(left, mid, right);   
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) {
            int num;
            scanf("%d",&num);
            arr[i] = num;
        }
    } 
    QuickSort(0, n - 1);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
