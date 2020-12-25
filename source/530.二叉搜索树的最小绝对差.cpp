/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
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
    int getMinimumDifference(TreeNode* root) {
        int diff = INT_MAX;
        int pre = -1;
        getMinimumDifference(root, pre, diff);
        return diff;
    }

    void getMinimumDifference(TreeNode* root, int& pre, int& diff) {
        if (!root) return;

        getMinimumDifference(root->left, pre, diff);
        if (pre >= 0) diff = min(diff, root->val - pre);
        pre = root->val;
        getMinimumDifference(root->right, pre, diff);
    }
};
// @lc code=end
