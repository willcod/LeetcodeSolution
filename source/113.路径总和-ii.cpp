/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (!root) return {};

        vector<vector<int>> res;
        vector<int> path;

        pathSum(root, sum, res, path);
        return res;
    }

    void pathSum(TreeNode* root, int sum, vector<vector<int>>& res,
                 vector<int>& path) {
        if (!root) return;

        sum -= root->val;
        path.push_back(root->val);

        if (sum == 0 && !root->left && !root->right) {
            res.push_back(path);
            return;
        }

        pathSum(root->left, sum, res, path);
        pathSum(root->right, sum, res, path);

        path.pop_back();
    }
};
// @lc code=end
