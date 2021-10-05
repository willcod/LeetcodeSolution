/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
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
  int kthSmallest(TreeNode* root, int k) {
    if (!root) return 0;
    priority_queue<int> q;

    travel(root, k, q);

    return q.top();
  }

  void travel(TreeNode* node, int k, priority_queue<int>& q) {
    if (!node) return;
    q.push(node->val);
    if (q.size() > k) q.pop();

    if (node->left) travel(node->left, k, q);
    if (node->right) travel(node->right, k, q);
  }
};
// @lc code=end
