#define MaxSize 10

typedef struct {
    int data[MaxSize];
    int front;  // 指向队头元素
    int rear;   // 指向下一个应插入的位置
} SeqQueue;

// 初始化队列
void InitQueue(SeqQueue &q) {
    q.front = q.rear = 0;
}

// 入队
bool EnQueue(SeqQueue &q, int e) {
    if (QueueFull(q)) {
        return false;
    }
    q.data[q.rear] = e;
    q.rear = (q.rear + 1) % MaxSize;    // 用模运算将存储空间在逻辑上变成了环状的
    return true;
}

// 出队
bool DeQueue(SeqQueue &q, int &e) {
    if (QueueEmpty(q)) {
        return false;
    }
    e = q.data[q.front];
    q.front = (q.front + 1) % MaxSize;
    return true;
}

// 读取队头元素
bool GetHead(SeqQueue q, int &e) {
    if (QueueEmpty(q)) {
        return false;
    }
    e = q.data[q.front];
    return true;
}

// 判断队空
bool QueueEmpty(SeqQueue q) {
    return q.rear == q.front;
}

// 判断队满
bool QueueFull(SeqQueue q) {
    return (q.rear + 1) % MaxSize == q.front;
}
