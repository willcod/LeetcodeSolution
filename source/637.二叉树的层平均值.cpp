/*
 * @lc app=leetcode.cn id=637 lang=cpp
 *
 * [637] 二叉树的层平均值
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
    vector<double> averageOfLevels(TreeNode* root) {
        if (!root) return {};

        vector<double> result;

        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int n = q.size();
            
            double sum =0;
            for (int i = 0; i < n; i++) {
                auto node = q.front();
                q.pop();
                sum += node->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            result.push_back(sum / n);
        }
        return result;
    }
};
// @lc code=end

