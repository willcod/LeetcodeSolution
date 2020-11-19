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
    return total(root, 0);
  }

  int total(TreeNode* root, int pre) {
    if (!root) return 0;
    pre = pre * 10 + root->val;

    if (root->left == nullptr && root->right == nullptr) return pre;

    int left = total(root->left, pre);
    int right = total(root->right, pre);

    return left + right;
  }
};
// @lc code=end
