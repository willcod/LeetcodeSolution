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
        unordered_map<int, int> inMap;
        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }

        int ps = 0;
        return buildTree(preorder, inorder, inMap, ps, 0, inorder.size() - 1);
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder,
                        unordered_map<int, int>& inMap, int& ps, int is,
                        int ie) {
        if (ps >= preorder.size() || is > ie) return nullptr;

        auto root = new TreeNode(preorder[ps]);
        int pos = inMap[preorder[ps]];
        ps++;

        root->left = buildTree(preorder, inorder, inMap, ps, is, pos - 1);
        root->right = buildTree(preorder, inorder, inMap, ps, pos + 1, ie);
        return root;
    }
};
// @lc code=end
