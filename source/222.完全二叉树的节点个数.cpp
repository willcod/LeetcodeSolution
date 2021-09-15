/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
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
    int countNodes(TreeNode* root) {
        int count = 0;
        traverse(root, count);
        return count;
    }

    void traverse(TreeNode* node, int& count) {
        if (!node) return;
        traverse(node->left, count);
        count++;
        traverse(node->right, count);
    }
};
// @lc code=end

