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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
   public:
    bool isValidBST(TreeNode* root) {
        if (!root) return true;

        bool left = isValidBST(root->left);
        if (pre != nullptr) {
            if (root->val <= pre->val) return false;
        }

        pre = root;

        return left && isValidBST(root->right);
    }

   private:
    TreeNode* pre = nullptr;
};
// @lc code=end
