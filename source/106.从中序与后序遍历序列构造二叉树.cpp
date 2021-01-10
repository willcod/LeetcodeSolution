/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.empty() || postorder.empty()) return nullptr;
        for (int i = 0; i < inorder.size(); i++) {
            intable[inorder[i]] = i;
        }

        return build(postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }

    TreeNode* build(vector<int>& postorder, int is, int ie, int ps, int pe) {
        if (is > ie || ps > pe) return nullptr;

        auto root = new TreeNode(postorder[pe]);
        int pos = intable[postorder[pe]];

        root->left = build(postorder, is, pos - 1, ps, ps + pos - is - 1);
        root->right = build(postorder, pos + 1, ie, ps + pos - is, pe - 1);
        return root;
    }

   private:
    unordered_map<int, int> intable;
};
// @lc code=end
