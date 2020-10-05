/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
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
    TreeNode* convertBST(TreeNode* root) {
        if (!root) return NULL;
        int sum = 0;
        return convert(root, sum);
    }

    TreeNode* convert(TreeNode* root, int& sum) {
        if (!root) return NULL;

        convert(root->right, sum);

        sum += root->val;
        root->val = sum;

        convert(root->left, sum);

        return root;
    }
};
// @lc code=end
