/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
  vector<int> preorderTraversal(TreeNode* root) {
    if (!root) return {};
    vector<int> result;
    stack<TreeNode*> stk;
    stk.push(root);

    while (!stk.empty()) {
      auto node = stk.top();
      if (node) {
        stk.pop();

        if (node->right) stk.push(node->right);
        if (node->left) stk.push(node->left);

        stk.push(node);
        stk.push(NULL);
      } else {
        stk.pop();
        auto n = stk.top();
        stk.pop();
        result.push_back(n->val);
      }
    }
    return result;
  }
};
// @lc code=end
