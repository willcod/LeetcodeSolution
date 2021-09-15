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
        int maxFreq = 0, currFreq = 0, preVal = INT_MIN;

        findMode(res, root, maxFreq, currFreq, preVal);
        return res;
    }

    void findMode(vector<int>& res, TreeNode* root, int& maxFreq, int& currFreq,
                  int& preVal) {
        if (!root) return;
        findMode(res, root->left, maxFreq, currFreq, preVal);

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
        findMode(res, root->right, maxFreq, currFreq, preVal);
    }
};
// @lc code=end
