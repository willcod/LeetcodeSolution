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
   private:
   public:
    int getMinimumDifference(TreeNode* root) {
        if (!root) return 0;
        int pre = -1;
        int minDiff = INT_MAX;

        getMinDiff(root, pre, minDiff);
        return minDiff;
    }

    void getMinDiff(TreeNode* root, int& pre, int& minDiff) {
        if (!root) return;

        getMinDiff(root->left, pre, minDiff);
        if (pre >= 0) minDiff = min(minDiff, (root->val - pre));
        pre = root->val;
        getMinDiff(root->right, pre, minDiff);
    }
};
// @lc code=end
