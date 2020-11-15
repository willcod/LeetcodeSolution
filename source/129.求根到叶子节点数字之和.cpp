/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根到叶子节点数字之和
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
    int sumNumbers(TreeNode* root) {
        if (!root) return 0;

        return sumNumber(root, 0);
    }

    int sumNumber(TreeNode* root, int pre) {
        if (!root) return 0;
        int num = pre*10+root->val;
        if (!root->left && !root->right)
            return num;

        int left = sumNumber(root->left, num);
        int right = sumNumber(root->right, num);

        return left + right;
    }
};
// @lc code=end

