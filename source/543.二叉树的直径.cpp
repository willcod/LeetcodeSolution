/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
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
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        int res = 1;
        depth(root, res);
        return res - 1;
    }

    int depth(TreeNode* node, int& res) {
        if (!node) return 0;

        int left = depth(node->left, res);
        int right = depth(node->right, res);

        res = max(res, left + right + 1);
        return max(left, right) + 1;
    }
};
// @lc code=end
