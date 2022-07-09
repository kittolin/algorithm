#include <stdlib.h>

typedef struct LinkNode {
    int data;
    struct LinkNode *next;
} LinkNode;

typedef struct {
    LinkNode *front, *rear;
} LinkQueue;

// 初始化链队列 (带头结点)
void InitQueue(LinkQueue &q) {
    q.front = q.rear = (LinkNode *)malloc(sizeof(LinkNode));
    q.front->next = NULL;
}

// 入队
bool EnQueue(LinkQueue &q, int e) {
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
    if (s == NULL) {    // 内存分配失败
        return false;
    }
    s->data = e;
    s->next = NULL;

    q.rear->next = s;
    q.rear = s;     // 表尾指针往后移
    return true;
}

// 出队
bool DeQueue(LinkQueue &q, int &e) {
    if (QueueEmpty(q)) {
        return false;
    }
    LinkNode *s = q.front->next;    // 待出队元素
    e = s->data;
    q.front->next = s->next;
    if (q.rear == s) {  // 如果是最后一个元素出队，需要修改队尾指针
        q.rear = q.front;
    }
    free(s);
    return true;
}

// 读取队头元素
bool GetHead(LinkQueue q, int &e) {
    if (QueueEmpty(q)) {
        return false;
    }
    e = q.front->next->data;
    return true;
}

// 判断队空
bool QueueEmpty(LinkQueue q) {
    return q.front == q.rear;
}
