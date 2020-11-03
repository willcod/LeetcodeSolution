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
        int min = INT_MAX;
        int pre = -1;

        getMin(root, pre, min);
        return min;
    }

    void getMin(TreeNode* root, int& pre, int& min) {
        if (!root) return;

        getMin(root->left, pre, min);
        if (pre >= 0) min = std::min(min, root->val - pre);
        pre = root->val;

        getMin(root->right, pre, min);
    }
};
// @lc code=end
