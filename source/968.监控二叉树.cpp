/*
 * @lc app=leetcode.cn id=968 lang=cpp
 *
 * [968] 监控二叉树
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
    int minCameraCover(TreeNode* root) {
        int sum = 0;
        if (travel(root, sum) == 0) {
            sum++;
        }

        return sum;
    }

    int travel(TreeNode* root, int& sum) {
        if (!root) return 2;

        int left = travel(root->left, sum);
        int right = travel(root->right, sum);

        if (left == 0 || right == 0) {
            sum++;
            return 1;
        }

        if (left == 1 || right == 1) return 2;

        if (left == 2 && right == 2) {
            return 0;
        }

        return -1;
    }
};
// @lc code=end
