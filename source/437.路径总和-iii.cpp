/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
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
    int pathSum(TreeNode* root, int sum) {
        if (!root) return 0;

        return countPath(root, sum) + pathSum(root->left, sum) +
               pathSum(root->right, sum);
    }

    int countPath(TreeNode* root, int sum) {
        if (!root) return 0;

        sum -= root->val;

        int res = sum == 0;

        return res + countPath(root->left, sum) + countPath(root->right, sum);
    }
};
// @lc code=end
