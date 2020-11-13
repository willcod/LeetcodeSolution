/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;

        return isSym(root->left, root->right);
    }

    bool isSym(TreeNode* left, TreeNode* right) {
        if (!left && !right) return true;
        if (!left || !right) return false;

        return left->val == right->val && isSym(left->left, right->right) &&
               isSym(left->right, right->left);
    }
};
// @lc code=end
