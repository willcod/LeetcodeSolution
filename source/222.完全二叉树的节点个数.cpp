/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
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
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int count = 0;
        travel(root, count);

        return count;
    }

    void travel(TreeNode* root, int& count) {
        if (!root) return;
        count++;

        if (root->left) travel(root->left, count);
        if (root->right) travel(root->right, count);
    }
};
// @lc code=end
