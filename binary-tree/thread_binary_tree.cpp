
// 线索二叉树结点
typedef struct ThreadNode {
    int data;
    struct ThreadNode *left, *right;
    int ltag, rtag;     // tag == 0 表指针指向孩子，tag == 1 表指针指向线索
} ThreadNode, *ThreadTree;

ThreadNode *pre = nullptr;     // 用全局变量 pre 来指向当前访问结点的前驱

void visit(ThreadNode *cur) {
    if (cur->left == nullptr) {     // 若左子树为空，则建立当前结点的前驱线索
        cur->left = pre;
        cur->ltag = 1;
    }
    if (pre != nullptr && pre->right == nullptr) {  // 若前驱的右子树为空，则建立前驱结点的后继线索
        pre->right = cur;
        pre->rtag = 1;
    }
    pre = cur;
}

// 中序遍历二叉树，并进行线索化
void InThread(ThreadTree t) {
    if (t != nullptr) {
        InThread(t->left);
        visit(t);
        InThread(t->right);
    }
}

// 中序线索化二叉树
void CreateInThread(ThreadTree t) {
    pre = nullptr;
    if (t != nullptr) {
        InThread(t);
        if (pre->right == nullptr) {    // 在中序遍历完后，pre 指向中序序列的最后一个结点
            pre->rtag = 1;
        }
    }
}

// 先序遍历二叉树，并进行线索化
void PreThread(ThreadTree t) {
    if (t != nullptr) {
        visit(t);
        if (t->ltag == 0) {     // 避免在两个结点间来回转圈的问题
            PreThread(t->left);
        }
        PreThread(t->right);
    }
}

// 先序线索化二叉树
void CreatePreThread(ThreadTree t) {
    pre = nullptr;
    if (t != nullptr) {
        PreThread(t);
        if (pre->right == nullptr) {    // 在先序遍历完后，pre 指向先序序列的最后一个结点
            pre->rtag = 1;
        }
    }
}

// 后序遍历二叉树，并进行线索化
void PostThread(ThreadTree t) {
    if (t != nullptr) {
        PostThread(t->left);
        PostThread(t->right);
        visit(t);
    }
}

// 后序线索化二叉树
void CreatePostThread(ThreadTree t) {
    pre = nullptr;
    if (t != nullptr) {
        PostThread(t);
        if (pre->right == nullptr) {    // 在后序遍历完后，pre 指向后序序列的最后一个结点
            pre->rtag = 1;
        }
    }
}

// 找到以 p 为根的子树中，第一个被中序遍历的结点
ThreadNode* InOrderFirstNode(ThreadNode *p) {
    // 循环找到最左下结点（不一定是叶子结点）
    while (p->ltag == 0) {
        p = p->left;
    }
    return p;
}

// 在中序线索二叉树中找到指定结点 p 的后继结点
ThreadNode* InThreadNextNode(ThreadNode *p) {
    if (p->rtag == 1) {
        return p->right; 
    }
    return InOrderFirstNode(p->right);  // 右子树中最左下结点
}

// 找到以 p 为根的子树中，最后一个被中序遍历的结点
ThreadNode* InOrderLastNode(ThreadNode *p) {
    // 循环找到最右下结点（不一定是叶子结点）
    while (p->rtag == 0) {
        p = p->right;
    }
    return p;
}

// 在中序线索二叉树中找到指定结点 p 的前驱结点
ThreadNode* InThreadPreNode(ThreadNode *p) {
    if (p->ltag == 1) {
        return p->left;
    }
    return InOrderLastNode(p->left);    // 左子树中最右下结点
}
