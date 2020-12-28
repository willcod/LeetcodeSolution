/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
 */
#include "cpp_includes.h"
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
   public:
    void recoverTree(TreeNode* root) {
        if (!root) return;

        TreeNode* pre = NULL;
        TreeNode* first = NULL;
        TreeNode* second = NULL;

        travel(root, pre, first, second);
        swap(first->val, second->val);
    }

    void travel(TreeNode* node, TreeNode*& pre, TreeNode*& first,
                TreeNode*& second) {
        if (!node) return;

        travel(node->left, pre, first, second);

        if (pre) {
            if (pre->val > node->val) {
                if (!first) {
                    first = pre;
                }
                second = node;
            }
        }

        pre = node;

        travel(node->right, pre, first, second);
    }
};
// @lc code=end
