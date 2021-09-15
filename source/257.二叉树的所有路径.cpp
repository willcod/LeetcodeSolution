/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root) return {};

        vector<string> res;
        traverse(root, res, to_string(root->val));
        return res;
    }

    void traverse(TreeNode* root, vector<string>& res, string path) {
        if (!root) return;
        if (!root->left && !root->right) {
            res.push_back(path);
            return;
        }

        if (root->left)
            traverse(root->left, res, path + "->" + to_string(root->left->val));

        if (root->right)
            traverse(root->right, res,
                     path + "->" + to_string(root->right->val));
    }
};
// @lc code=end
