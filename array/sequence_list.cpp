#include <stdlib.h>
#define InitCapacity 10

// 静态分配，不能扩展容量
typedef struct {
    int data[InitCapacity];
    int size;
} SSeqList;

// 插入元素
bool ListInsert(SSeqList& l, int i, int e) {
    if (i < 1 || i > l.size + 1) {
        return false;
    }
    if (l.size >= InitCapacity) {   // 当前存储空间已满
        return false;
    }

    // 将第 i 个位置后的所有元素后移
    for (int j = l.size - 1; j >= i - 1; j--) {
        l.data[j + 1] = l.data[j];
    }
    l.data[i - 1] = e;
    l.size ++;
    return true;
}

// 删除元素
bool ListDelete(SSeqList& l, int i, int& e) {
    if (i < 1 || i > l.size) {
        return false;
    }

    e = l.data[i - 1];
    // 将第 i 个位置后的所有元素前移
    for (int j = i; j < l.size; j++) {
        l.data[j - 1] = l.data[j];
    }
    l.size --;  // 元素前移后才能将 size - 1
    return true;
}

// 按位查找，位序从 1 开始
int GetElem(SSeqList l, int i) {
    return l.data[i - 1];
}

// 按值查找，返回位序
int LocateElem(SSeqList l, int e) {
    for (int i = 0; i < l.size; i++) {
        if (l.data[i] == e) {
            return i + 1;
        }
    }
    return 0;
}


// 动态分配，可以扩展容量
typedef struct {
    int *data;
    int capacity;   // 最大容量
    int size;       // 实际存储元素个数
} DSeqList;

// 初始化动态顺序表
void InitList(DSeqList& l) {
    l.data = (int *)malloc(InitCapacity * sizeof(int));
    l.capacity = InitCapacity;
    l.size = 0;
}

// 增加动态顺序表的容量
void IncreaseCapacity(DSeqList& l, int cap) {
    int *old = l.data;
    l.data = (int *)malloc((l.capacity + cap) * sizeof(int));
    l.capacity += cap;

    for (int i = 0; i < l.size; i++) {
        l.data[i] = old[i];
    }
    free(old);
}
