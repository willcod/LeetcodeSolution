/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int, int> hash;
    for (int i = 0; i < inorder.size(); i++) hash[inorder[i]] = i;

    int depth = 0;
    return build(preorder, inorder, hash, 0, inorder.size() - 1, depth);
  }

  TreeNode* build(vector<int>& preorder, vector<int>& inorder,
                  unordered_map<int, int>& hash, int start, int end, int& ps) {
    if (ps >= inorder.size() || start > end) return NULL;

    auto root = new TreeNode(preorder[ps]);
    int in = hash[preorder[ps]];
    ps++;

    root->left = build(preorder, inorder, hash, start, in - 1, ps);
    root->right = build(preorder, inorder, hash, in + 1, end, ps);
    return root;
  }
};
// @lc code=end
