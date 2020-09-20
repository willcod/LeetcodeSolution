/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层次遍历 II
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (!root) return {};

        int n = depth(root);
        vector<vector<int>> res(n);
        travel(res, root, n - 1);
        return res;
    }

    void travel(vector<vector<int>>& res, TreeNode* root, int n) {
        if (!root) return;

        res[n].push_back(root->val);
        travel(res, root->left, n - 1);
        travel(res, root->right, n - 1);
    } 

    int depth(TreeNode* root) {
        if (!root) return 0;

        return max(depth(root->left), depth(root->right)) + 1;
    }
};
// @lc code=end

