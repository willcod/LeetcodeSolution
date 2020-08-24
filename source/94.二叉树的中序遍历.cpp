/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
  vector<int> inorderTraversal(TreeNode* root) {
    if (!root) return {};

    vector<int> result;
    stack<TreeNode*> stk;
    stk.push(root);

    while (!stk.empty()) {
      auto n = stk.top();
      if (n) {
        stk.pop();

        if (n->right) stk.push(n->right);
        stk.push(n);
        stk.push(NULL);
        if (n->left) stk.push(n->left);
      } else {
        stk.pop();
        auto node = stk.top();
        stk.pop();
        result.push_back(node->val);
      }
    }
    return result;
  }
};
// @lc code=end
