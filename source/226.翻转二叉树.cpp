/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
 */
#include "cpp_includes.h"
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return root;

        stack<TreeNode*> stk;
        stk.push(root);

        while (!stk.empty()) {
            auto node = stk.top();
            stk.pop();

            auto temp = node->right;
            node->right = node->left;
            node->left = temp;

            if (node->left) stk.push(node->left);
            if (node->right) stk.push(node->right);
        }

        return root;
    }
};
// @lc code=end

