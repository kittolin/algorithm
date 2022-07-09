#define MaxSize 10

typedef struct {
    int data[MaxSize];
    int top;    // 栈顶指针，指向栈顶元素
} SeqStack;

// 初始化栈
void InitStack(SeqStack &s) {
    s.top = -1;
}

// 进栈，时间复杂度 O(1)
bool Push(SeqStack &s, int e) {
    if (s.top == MaxSize - 1) {     // 栈满
        return false;
    }
    s.data[++ s.top] = e;
    return true;
}

// 出栈，时间复杂度 O(1)
bool Pop(SeqStack &s, int &e) {
    if (StackEmpty(s)) {
        return false;
    }
    e = s.data[s.top --];
    return true;
}

// 读栈顶元素，时间复杂度 O(1)
bool GetTop(SeqStack s, int &e) {
    if (StackEmpty(s)) {
        return false;
    }
    e = s.data[s.top];
    return true;
}

// 判断栈空
bool StackEmpty(SeqStack s) {
    return s.top == -1;
}
