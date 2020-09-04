/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
  vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> result;
    if (!root) return {};

    travel(result, root, to_string(root->val));

    return result;
  }

  void travel(vector<string>& result, TreeNode* root, string path) {
    if (!root) return;

    if (!root->left && !root->right) {
      result.push_back(path);
      return;
    }

    if (root->left) 
        travel(result, root->left, path + "->" + to_string(root->left->val));
    if (root->right) 
        travel(result, root->right, path + "->" + to_string(root->right->val));
  }
};
// @lc code=end
