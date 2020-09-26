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
        int preVal = 0, currFreq = 0, maxFreq = 0;
        morrisInorder(res, root, preVal, currFreq, maxFreq);
        return res;
    }

    void morrisInorder(vector<int>& res, TreeNode* root, int& preVal,
                       int& currFreq, int& maxFreq) {
        if (!root) return;

        morrisInorder(res, root->left, preVal, currFreq, maxFreq);
        if (preVal == root->val)
            currFreq++;
        else
            currFreq = 1;

        if (currFreq > maxFreq) {
            res.clear();
            maxFreq = currFreq;
            res.push_back(root->val);
        } else if (currFreq == maxFreq) {
            res.push_back(root->val);
        }

        preVal = root->val;

        morrisInorder(res, root->right, preVal, currFreq, maxFreq);
    }
};
// @lc code=end
