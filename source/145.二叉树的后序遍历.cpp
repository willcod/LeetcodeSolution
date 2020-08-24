/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
  vector<int> postorderTraversal(TreeNode* root) {
    if (!root) return {};

    vector<int> result;
    stack<TreeNode*> stk;
    stk.push(root);
    while (!stk.empty()) {
      TreeNode* node = stk.top();
      if (node) {
        stk.pop();

        stk.push(node);
        stk.push(NULL);
        if (node->right) stk.push(node->right);
        if (node->left) stk.push(node->left);

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
