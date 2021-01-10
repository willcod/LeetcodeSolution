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

    void pathSum(TreeNode* node, int sum, vector<vector<int>>& res,
                 vector<int>& path) 
    {
        if (!node) return;
        path.push_back(node->val);
        sum -= node->val;

        if (sum == 0 && !node->left && !node->right) {
            res.push_back(path);
        }

        pathSum(node->left, sum, res, path);
        pathSum(node->right, sum, res, path);

        path.pop_back();
    }
};
// @lc code=end
