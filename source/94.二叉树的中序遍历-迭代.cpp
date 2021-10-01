/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
  vector<int> inorderTraversal(TreeNode* root) {
    if (!root) return {};

    vector<int> res;
    stack<TreeNode*> stk;
    stk.push(root);

    while (!stk.empty()) {
      auto node = stk.top();
      stk.pop();

      if (node) {
        if (node->right) stk.push(node->right);

        stk.push(node);
        stk.push(nullptr);

        if (node->left) stk.push(node->left);
      } else {
        auto n = stk.top();
        stk.pop();
        res.push_back(n->val);
      }
    }

    return res;
  }
};
// @lc code=end
