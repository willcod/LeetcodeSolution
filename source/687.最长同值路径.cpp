/*
 * @lc app=leetcode.cn id=687 lang=cpp
 *
 * [687] 最长同值路径
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
    int longestUnivaluePath(TreeNode* root) {
        if (!root) return 0;

        int res = 0;
        longestUnivaluePath(root, res);

        return res;
    }

    int longestUnivaluePath(TreeNode* node, int& res) {
        if (!node) return 0;

        int left = longestUnivaluePath(node->left, res);
        int right = longestUnivaluePath(node->right, res);

        left = (node->left && node->val == node->left->val) ? left + 1 : 0;
        right = (node->right && node->val == node->right->val) ? right + 1 : 0;

        res = max(res, left + right);
        return max(left, right);
    }
};
// @lc code=end
