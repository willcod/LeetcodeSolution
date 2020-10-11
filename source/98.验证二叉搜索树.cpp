/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
    long _pre = LONG_MIN;
    bool isValidBST(TreeNode* root) {
        if (!root) return true;

        if (isValidBST(root->left) == false) return false;

        if (_pre >= root->val) return false;

        _pre = root->val;
        return isValidBST(root->right);
    }
};
// @lc code=end
