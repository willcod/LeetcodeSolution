/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
 */

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        travel(res, root);
        return res;
    }

    void travel(vector<int>& res, TreeNode* root) {
        if (!root) return;
        if (root->left) travel(res, root->left);
        if (root->right) travel(res, root->right);

        res.push_back(root->val);
    }
};
// @lc code=end

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) return {};
        vector<int> result;
        stack<TreeNode*> stk;

        stk.push(root);

        while (!stk.empty()) {
            auto node = stk.top();
            if (node) {
                stk.pop();

                stk.push(node);
                stk.push(NULL);

                if (node->right) stk.push(node->right);
                if (node->left) stk.push(node->left);
            } else {
                stk.pop();
                auto n = stk.top();
                stk.pop();

                result.push_back(n->val);
            }
        }
        return result;
    }
};