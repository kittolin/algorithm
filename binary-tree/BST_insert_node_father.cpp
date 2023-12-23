/*
* 名称：二叉排序树插入节点，返回其父亲节点

* 链接：http://985.so/9cmi
* 难度：中等
*/

#include <iostream>
#include <cstdio>

using namespace std;

struct BSTNode {
    int data;
    BSTNode* left;
    BSTNode* right;
    BSTNode(int d): data(d), left(nullptr), right(nullptr) {}
};

BSTNode* Insert(BSTNode* root, int data, int father) { // father: 当前 root 节点的父亲节点数值
    if (root == nullptr) {
        printf("%d\n", father);
        return new BSTNode(data);
    }

    if (data > root->data) {
        root->right = Insert(root->right, data, root->data);
    } else if (data < root->data) {
        root->left = Insert(root->left, data, root->data);
    }
    return root;
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        BSTNode* root = nullptr;
        while (n --) {
            int data;
            scanf("%d", &data);
            root = Insert(root, data, -1);
        }
    }
    return 0;
}
