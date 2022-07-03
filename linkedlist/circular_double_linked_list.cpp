#include <stdlib.h>

typedef struct CDLNode {
    int data;
    struct CDLNode *prior, *next;
} CDLNode, *CDLinkList;

// 初始化空的循环双链表
bool InitCDLinkList(CDLinkList &l) {
    l = (CDLinkList)malloc(sizeof(CDLNode));
    if (l == NULL) {    // 内存分配失败
        return false;
    }

    l->prior = l;
    l->next = l;
    return true;
}

// 在 p 结点后插入 s 结点
bool InsertNextNode(CDLNode *p, CDLNode *s) {
    if (p == NULL || s == NULL) {
        return false;
    }

    // 修改指针要注意顺序
    s->next = p->next;
    p->next->prior = s;  // 和普通双链表相比，不用判断 p 是否为最后一个结点
    s->prior = p;
    p->next = s;
    return true;
}
  
// 删除 p 的后继结点
bool DeleteNextNode(CDLinkList &l, CDLNode *p) {
    if (p == NULL || IsTail(l, p)) {
        return false;
    }

    CDLNode *s = p->next;
    p->next = s->next;
    s->next->prior = p;  // 和普通双链表相比，不用判断 s 是否为最后一个结点
    free(s);
    return true;
}

// 判断 p 结点是否为表尾结点
bool IsTail(CDLinkList l, CDLNode *p) {
    return p->next == l;
}

// 判断循环双链表是否为空 
bool Empty(CDLinkList l) {
    return l->next == l;
}
