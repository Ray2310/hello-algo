/**
 * File: preorder_traversal_i_compact.cpp
 * Created Time: 2023-04-16
 * Author: Krahets (krahets@163.com)
 */

#include "../include/include.hpp"

vector<TreeNode *> res;

/* 前序遍历：例题一 */
static void preOrder(TreeNode *root) {
    if (root == nullptr) {
        return;
    }
    if (root->val == 7) {
        // 记录解
        res.push_back(root);
    }
    preOrder(root->left);
    preOrder(root->right);
}

/* Driver Code */
int main() {
    TreeNode *root = vecToTree(vector<int>{1, 7, 3, 4, 5, 6, 7});
    cout << "\n初始化二叉树" << endl;
    printTree(root);

    // 前序遍历
    preOrder(root);

    cout << "\n输出所有值为 7 的节点" << endl;
    vector<int> vals;
    for (TreeNode *node : res) {
        vals.push_back(node->val);
    }
    printVector(vals);
}
