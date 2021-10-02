/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inHashmap;
        for (int i = 0; i < inorder.size(); i++) {
            inHashmap[inorder[i]] = i;
        }

        int preorderIndex = 0;
        return buildTree(preorder, inHashmap, 0, inorder.size()-1, preorderIndex);
    }

    TreeNode* buildTree(vector<int>& preorder, unordered_map<int,int>& inhashMap, int is, int ie, int& ps) {
        if (ps == preorder.size() || is > ie) return nullptr;

        auto node = new TreeNode(preorder[ps]);
        int inorderIndex = inhashMap[preorder[ps]];
        ps++;

        node->left = buildTree(preorder, inhashMap, is, inorderIndex-1, ps);
        node->right = buildTree(preorder, inhashMap, inorderIndex+1, ie, ps);

        return node;
    }
};
// @lc code=end

