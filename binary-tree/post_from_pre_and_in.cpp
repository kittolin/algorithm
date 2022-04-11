/*
* 名称：给定先序序列和中序序列，确定后续序列
* 来源：华中科技大学复试上机题
* 链接：http://t.cn/AiKgDfLU
* 难度：中等
*/

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

struct TreeNode {
    char data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char c): data(c), left(nullptr), right(nullptr) {}
};

// 给定先序序列和中序序列，构建二叉树
TreeNode* Build(string preOrder, string inOrder) {
    if (preOrder.size() == 0) {
        return nullptr;
    }
    TreeNode* root = new TreeNode(preOrder[0]);
    int pos = inOrder.find(preOrder[0]);
    root->left = Build(preOrder.substr(1, pos), inOrder.substr(0, pos));
    root->right = Build(preOrder.substr(pos + 1), inOrder.substr(pos + 1));
    return root;
}

void PostOrder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    printf("%c", root->data);
}

int main() {
    string preOrder, inOrder;
    while (cin >> preOrder >> inOrder) {
        TreeNode* root = Build(preOrder, inOrder);
        PostOrder(root);
        printf("\n");
    }
    return 0;
}
