/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
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
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        int count = 0;
        int maxCount = 0;
        int preVal = 0;
        travel(root, res, preVal, count, maxCount);
        return res;
    }

    void travel(TreeNode* root, vector<int>& res, int& preVal, int& count,
                int& maxCount) {
        if (!root) return;

        travel(root->left, res, preVal, count, maxCount);

        if (root->val == preVal) {
            count++;
        } else {
            count = 1;
        }

        if (count > maxCount) {
            maxCount = count;
            res.clear();
            res.push_back(root->val);
        } else if (count == maxCount) {
            res.push_back(root->val);
        }

        preVal = root->val;

        travel(root->right, res, preVal, count, maxCount);
    }
};
// @lc code=end
