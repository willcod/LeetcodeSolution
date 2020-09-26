/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0 || postorder.size() == 0) return NULL;
        for (int i = 0; i < inorder.size(); i++) {
            table[inorder[i]] = i;
        }
        return build(inorder, postorder, 0, inorder.size() - 1, 0,
                     postorder.size() - 1);
    }

    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int is,
                    int ie, int ps, int pe) {
        if (ps > pe) return NULL;
    }

   private:
    unordered_map<int, int> table;
};

// @lc code=end
