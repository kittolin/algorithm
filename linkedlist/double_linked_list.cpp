#include <stdlib.h>

typedef struct DLNode {
    int data;
    struct DLNode *prior, *next;
} DLNode, *DLinkList;

// 初始化双链表（带头结点）
bool InitDLinkList(DLinkList &l) {
    l = (DLinkList)malloc(sizeof(DLNode));
    if (l == NULL) {    // 内存分配失败
        return false;
    }

    l->prior = NULL;
    l->next = NULL;
    return true;
}

// 在 p 结点后插入 s 结点
bool InsertNextNode(DLNode *p, DLNode *s) {
    if (p == NULL || s == NULL) {
        return false;
    }

    // 修改指针要注意顺序
    s->next = p->next;
    if (p->next != NULL) {  // 防止 p 结点是最后一个结点
        p->next->prior = s;
    }
    s->prior = p;
    p->next = s;
    return true;
}

// 删除 p 的后继结点
bool DeleteNextNode(DLNode *p) {
    if (p == NULL) {
        return false;
    }
    DLNode *s = p->next;
    if (s == NULL) {  // p 没有后继结点，删除失败
        return false;
    }

    p->next = s->next;
    if (s->next != NULL) {  // 防止 s 是最后一个结点
        s->next->prior = p;
    }
    free(s);
    return true;
}

// 判断双链表是否为空（带头结点）
bool Empty(DLinkList l) {
    return l->next == NULL;
}
