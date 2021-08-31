/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
    long pre = LONG_MIN;

    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        
        if (!isValidBST(root->left)) return false;

        if (root->val <= pre) return false;
        pre = root->val;

        return isValidBST(root->right);
    }
};
// @lc code=end

