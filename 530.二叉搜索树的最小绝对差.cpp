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

        int res = INT_MAX;
        int pre = -1;
        traverse(root, res, pre);
        return res;
    }

    void traverse(TreeNode* node, int& res, int& pre) {
        if (!node) return;

        traverse(node->left, res, pre);

        if (pre != -1) {
            res = min(res, node->val - pre);
        }
        pre = node->val;

        traverse(node->right, res, pre);
    }
};
// @lc code=end

