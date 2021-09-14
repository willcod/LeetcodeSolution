/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
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
    int rob(TreeNode* root) {
        if (!root) return 0;

        unordered_map<TreeNode*, int> cache;
        return robSub(root, cache);
    }

    int robSub(TreeNode* root, unordered_map<TreeNode*, int>& cache) {
        if (!root) return 0;
        if (cache.find(root) != cache.end()) return cache[root];

        // rob the root
        int sum = 0;
        if (root->left) {
            sum += robSub(root->left->left, cache) + robSub(root->left->right, cache);
        }
        if (root->right) {
            sum += robSub(root->right->left, cache) + robSub(root->right->right, cache);
        }

        int result = max(root->val + sum, robSub(root->left, cache) + robSub(root->right, cache));
        cache[root] = result;
        return result;
    }
};
// @lc code=end

