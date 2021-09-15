/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;

        if (!root->left && !root->right) {
            return root->val == sum;
        }

        return hasPathSum(root->left, sum-root->val) ||
            hasPathSum(root->right, sum-root->val);
    }
};
// @lc code=end
