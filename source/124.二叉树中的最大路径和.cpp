/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
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
    int maxPathSum(TreeNode* root) {
        int result = INT_MIN;
        travel(root, result);
        return result;
    }

    int travel(TreeNode* root, int& result) {
        if (!root) return 0;
        int left = max(0, travel(root->left, result));
        int right = max(0, travel(root->right, result));
        result = max(result, left + right + root->val);
        return max(left, right) + root->val;
    }
};
// @lc code=end
