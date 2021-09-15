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
        vector<int> nums;

        traverse(root, nums, 0);

        return accumulate(nums.begin(), nums.end(), 0);
    }

    void traverse(TreeNode* node, vector<int>& nums, int num) {
        if (!node) return;

        num = num * 10 + node->val;

        if (!node->left && !node->right) {
            nums.push_back(num);
        }

        traverse(node->left, nums, num);
        traverse(node->right, nums, num);
    }
};
// @lc code=end
