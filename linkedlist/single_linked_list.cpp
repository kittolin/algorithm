#include <stdlib.h>
#include <stdio.h>

typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *LinkList;

// 初始化单链表（带头结点） 
bool InitList(LinkList& l) {
    l = (LNode *)malloc(sizeof(LNode));
    if (l == NULL) {    // 内存不足，分配失败
        return false;
    }
    l->next = NULL;
    return true;
}

// 尾插法建立单链表
LinkList ListTailInsert() {
    // 初始化单链表
    LinkList l = (LinkList)malloc(sizeof(LNode));
    l->next = NULL;

    LNode *tail = l;    // 定义尾指针
    int x;
    scanf("%d", &x);
    while (x != -1) {
        LNode *s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        tail->next = s;
        tail = s;       // tail 指向新的表尾结点
        scanf("%d", &x);
    }

    tail->next = NULL;
    return l;
}

// 头插法建立单链表，可用于单链表的逆置
LinkList ListHeadInsert() {
    // 初始化单链表
    LinkList l = (LinkList)malloc(sizeof(LNode));
    l->next = NULL;

    int x;
    scanf("%d", &x);
    while (x != -1) {
        InsertNextNode(l, x);
        scanf("%d", &x);
    }
    return l;
}

// 按位序插入（带头结点）
bool ListInsert(LinkList& l, int i, int e) {
    if (i < 1) {
        return false;
    }

    LNode *p = GetElem(l, i - 1);   // 找到第 i-1 个结点
    if (p == NULL) {    // i 值不合法
        return false;
    }
    return InsertNextNode(p, e);
}

// 按位序插入（不带头结点）
bool ListInsert(LinkList& l, int i, int e) {
    if (i < 1) {
        return false;
    }

    // 如果不带头结点，则插入、删除第一个元素时，需要更改头指针
    if (i == 1) {
        LNode *s = (LNode *)malloc(sizeof(LNode));
        s->data = e;
        s->next = l;
        l = s;
        return true;
    }

    LNode *p = l;   // p 指向当前扫描到的结点
    int j = 1;      // 当前 p 指向第 j 个结点
    while (p != NULL && j < i - 1) {    // 循环找到第 i-1 个结点
        p = p->next;
        j ++;
    }

    if (p == NULL) {    // i 值不合法
        return false;
    }
    return InsertNextNode(p, e);
}

// 指定结点的后插
bool InsertNextNode(LNode *p, int e) {
    if (p == NULL) {
        return false;
    }
    LNode* s = (LNode *)malloc(sizeof(LNode));
    if (s == NULL) {    // 内存分配失败
        return false;
    }

    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

// 指定结点的前插，时间复杂度：O(1)
bool InsertPriorNode(LNode *p, int e) {
    if (p == NULL) {
        return false;
    }
    LNode* s = (LNode *)malloc(sizeof(LNode));
    if (s == NULL) {    // 内存分配失败
        return false;
    }

    s->data = p->data;  // 将 p 中元素复制到 s
    p->data = e;        // 将 p 中元素覆盖为 e
    s->next = p->next;
    p->next = s;
    return true;
}

// 按位删除（带头结点）
bool ListDelete(LinkList &l, int i, int& e) {
    if (i < 1) {
        return false;
    }
    LNode *p = GetElem(l, i - 1);   // 找到第 i-1 个结点
    if (p == NULL || p->next == NULL) { // 如果没有第 i-1 个结点或第 i 个结点，则删除失败
        return false;
    }

    LNode *s = p->next;  // 待删除的结点
    e = s->data;
    p->next = s->next;
    free(s);
    return true;
}

// 指定结点的删除
bool DeleteNode(LinkList &l, LNode *p) {
    if (p == NULL) {
        return false;
    }

    // 如果 p 是最后一个结点，只能从头找到 p 的前驱再进行删除
    if (p->next == NULL) {
        LNode *pre = l;
        while (pre->next != p) {
            pre = pre->next;
        }
        pre->next = p->next;
        free(p);
        return true;
    }

    // 将 p 的后继结点值覆盖 p 的结点值，再删除 p 的后继结点
    LNode *next = p->next;
    p->data = next->data;
    p->next = next->next;
    free(next);
    return true;
}

// 按位查找，线性表的位序从 1 开始，i = 0 时返回头结点
LNode* GetElem(LinkList &l, int i) {
    if (i < 0) {
        return NULL;
    }

    LNode *p = l;   // p 指向当前扫描到的结点
    int j = 0;      // 当前 p 指向的是第 j 个结点
    while (p != NULL && j < i) {    // 循环找到第 i 个结点
        p = p->next;
        j ++;
    }
    return p;       // i 超过链表长度时返回 NULL
}

// 按值查找（带头结点）
LNode* LocateElem(LinkList &l, int e) {
    LNode *p = l->next;
    while (p != NULL && p->data != e) {
        p = p->next;
    }
    return p;   // 如果找不到则返回 NULL

}

// 判断单链表是否为空（带头结点）
bool Empty(LinkList l) {
    return l->next == NULL;
}

// 求单链表长度（带头结点）
int Length(LinkList l) {
    int len = 0;
    LNode *p = l->next;
    while (p != NULL) {
        p = p->next;
        len ++;
    }
    return len;
}
