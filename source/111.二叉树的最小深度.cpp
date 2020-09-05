/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
 */

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
 int minDepth(TreeNode* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;

    int min = INT_MAX;
    if (root->left) {
      min = std::min(minDepth(root->left), min);
    }

    if (root->right) {
      min = std::min(minDepth(root->right), min);
    }
    return min + 1;
  }
};
// @lc code=end

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        if (!root->left) return minDepth(root->right) + 1;
        if (!root->right) return minDepth(root->left) + 1;

        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};