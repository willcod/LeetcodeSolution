/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    if (nums.empty()) return NULL;

    return BuildBST(nums, 0, nums.size() - 1);
  }

  TreeNode* BuildBST(vector<int>& nums, int lo, int hi) {
    if (lo > hi) return NULL;

    int mid = lo + (hi - lo) / 2;
    auto node = new TreeNode(nums[mid]);
    node->left = BuildBST(nums, lo, mid - 1);
    node->right = BuildBST(nums, mid + 1, hi);

    return node;
  }
};
// @lc code=end
