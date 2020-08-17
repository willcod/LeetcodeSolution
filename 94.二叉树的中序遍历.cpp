/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
// 递归
// class Solution {
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> result;
//         inorder(root, result);
//         return result;
//     }

//     void inorder(TreeNode* node, vector<int>& result) {
//         if (node == nullptr) return;

//         inorder(node->left, result);
//         result.push_back(node->val);
//         inorder(node->right, result);
//     }
// };

// 基于栈
// class Solution {
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
        
//         vector<int> res;
//         stack<TreeNode*> stk;

//         auto cur = root;
//         while (cur || !stk.empty()) {
//             while(cur) {
//                 stk.push(cur);
//                 cur = cur->left;
//             }

//             cur = stk.top(); stk.pop();
//             res.push_back(cur->val);
//             cur = cur->right;
//         }

//         return res;
//     }
// };


// @lc code=end

