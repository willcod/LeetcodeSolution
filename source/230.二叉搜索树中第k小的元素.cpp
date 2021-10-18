/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
 */
#include "cpp_includes.h"
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> vec;

        travel(root, vec);

        sort(vec.begin(), vec.end());



        return vec[k-1];
    }

    void travel(TreeNode* root, vector<int>& vec) {
        if (!root) return;

        vec.push_back(root->val);
        if (root->left) travel(root->left, vec);
        if (root->right) travel(root->right, vec);
    }
};
// @lc code=end

