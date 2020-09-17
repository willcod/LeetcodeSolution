/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
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
    void flatten(TreeNode* root) {
        if (!root) return;

        flatten(root->right);
        flatten(root->left);

        root->right = pre;
        root->left = NULL;
        pre = root;

    }

    private:
    TreeNode* pre;
};
// @lc code=end

class Solution {
 public:
  void flatten(TreeNode* root) {
    if (!root) return;

    auto current = root;
    while (current) {
      if (current->left) {
        auto pre = current->left;
        while (pre->right) {
          pre = pre->right;
        }
        pre->right = current->right;
        current->right = current->left;
        current->left = nullptr;
      }
      current = current->right;
    }
  }
};