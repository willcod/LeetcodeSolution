/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
    bool isBalanced(TreeNode* root) {
        if (!root) return true;

        int l = level(root->left);
        int r = level(root->right);

        return abs(l - r) < 2 && isBalanced(root->left) &&
               isBalanced(root->right);
    }

    int level(TreeNode* node) {
        if (!node) return 0;

        return max(level(node->left), level(node->right)) + 1;
    }
};
// @lc code=end
