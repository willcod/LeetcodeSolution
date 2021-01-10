/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        if (!root) return root;

        int sum = 0;
        traverse(root, sum);
        return root;
    }

    void traverse(TreeNode* node, int&sum) {
        if (!node) return;

        if (node->right) traverse(node->right, sum);

        sum += node->val;
        node->val = sum;

        if (node->left) traverse(node->left, sum);
    }
};
// @lc code=end

