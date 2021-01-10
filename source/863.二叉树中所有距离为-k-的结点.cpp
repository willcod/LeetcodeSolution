/*
 * @lc app=leetcode.cn id=863 lang=cpp
 *
 * [863] 二叉树中所有距离为 K 的结点
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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        if (!root) return {};

        unordered_map<TreeNode*, TreeNode*> parent;
        findParent(root, parent);
        vector<int> res;
        unordered_set<TreeNode*> visited;
        findNode(target, K, res, parent, visited);

        return res;
    }

    void findParent(TreeNode* node,
                    unordered_map<TreeNode*, TreeNode*>& parent) {
        if (!node) return;

        if (node->left) {
            parent[node->left] = node;
            findParent(node->left, parent);
        }

        if (node->right) {
            parent[node->right] = node;
            findParent(node->right, parent);
        }
    }

    void findNode(TreeNode* node, int k, vector<int>& res,
                  unordered_map<TreeNode*, TreeNode*>& parent,
                  unordered_set<TreeNode*>& visited) {
        if (!node) return;

        if (visited.count(node)) return;

        visited.insert(node);

        if (k == 0) {
            res.push_back(node->val);
            return;
        }

        if (node->left) findNode(node->left, k - 1, res, parent, visited);
        if (node->right) findNode(node->right, k - 1, res, parent, visited);

        auto p = parent[node];
        if (p) findNode(p, k - 1, res, parent, visited);
    }
};
// @lc code=end
