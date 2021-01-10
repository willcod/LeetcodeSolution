/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        queue<TreeNode*> q;
        q.push(root);

        vector<vector<int>> res;
        int level = 0;
        while (!q.empty()) {
            int n = q.size();
            vector<int> layer(n, 0);

            for (int i = 0; i < n; i++) {
                auto node = q.front();
                q.pop();
                if (level % 2 == 0) {
                    layer[i] = node->val;
                } else {
                    layer[n - i - 1] = node->val;
                }

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            res.push_back(layer);
            level++;
        }

        return res;
    }
};
// @lc code=end
