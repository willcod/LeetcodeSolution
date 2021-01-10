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
        if (preorder.empty() || inorder.empty()) return {};

        for (int i = 0; i < inorder.size(); i++) {
            intable[inorder[i]] = i;
        }
        int ps = 0;
        return build(preorder, 0, inorder.size() - 1, ps);
    }

    TreeNode* build(vector<int>& preorder, int is, int ie, int& ps) {
        if (ps >= preorder.size() || is > ie) return nullptr;

        auto root = new TreeNode(preorder[ps]);
        int pos = intable[preorder[ps]];
        ps++;
        root->left = build(preorder, is, pos - 1, ps);
        root->right = build(preorder, pos + 1, ie, ps);

        return root;
    }

   private:
    unordered_map<int, int> intable;
};
// @lc code=end
