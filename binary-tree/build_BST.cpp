/*
* 名称：构建二叉排序树
* 来源：华中科技大学复试上机题
* 链接：http://t.cn/AiKD0L5V
* 难度：较难
*/

#include <iostream>
#include <cstdio>

using namespace std;

struct BSTNode {
    int data;
    BSTNode* left;
    BSTNode* right;
    BSTNode(int i): data(i), left(nullptr), right(nullptr) {}
};

BSTNode* Insert(BSTNode* root, int data) {
    if (root == nullptr) {
        return new BSTNode(data);
    }

    if (data < root->data) {
        root->left = Insert(root->left, data);
    } else if (data > root->data) {
        root->right = Insert(root->right, data);
    }
    return root;
}

void PreOrder(BSTNode* root) {
    if (root == nullptr) {
        return;
    }
    printf("%d ", root->data);
    PreOrder(root->left);
    PreOrder(root->right);
}

void InOrder(BSTNode* root) {
    if (root == nullptr) {
        return;
    }
    InOrder(root->left);
    printf("%d ", root->data);
    InOrder(root->right);
}

void PostOrder(BSTNode* root) {
    if (root == nullptr) {
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    printf("%d ", root->data);
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        BSTNode* root = nullptr;        
        for (int i = 0; i < n; i++) {
            int data;
            scanf("%d", &data);
            root = Insert(root, data);
        }
        PreOrder(root);
        printf("\n");
        InOrder(root);
        printf("\n");
        PostOrder(root);
        printf("\n");
    }
    return 0;
}
