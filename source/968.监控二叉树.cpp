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
        if (!root) return 0;

        int count = 0;
        if (cover(root, count) == 0) count++;
        return count;
    }

    int cover(TreeNode* root, int& count) {
        if (!root) return 2;

        int left = cover(root->left, count);
        int right = cover(root->right, count);

        if (left == 2 && right == 2) return 0;


        if (left == 0 || right == 0) {
            count++;
            return 1;
        }
        if (left == 1 || right == 1) {
            return 2;
        }
        return -1;
    }
};
// @lc code=end
