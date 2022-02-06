/*
 * @lc app=leetcode.cn id=236 lang=csharp
 *
 * [236] 二叉树的最近公共祖先
 */
using csharp;

// @lc code=start
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int x) { val = x; }
 * }
 */
public class Solution
{
    public TreeNode LowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q)
    {
        if (root == null || root == p || root == q) return root;

        var left = LowestCommonAncestor(root.left, p, q);
        var right = LowestCommonAncestor(root.right, p, q);

        if (left != null && right != null)
        {
            return root;
        }
        else if (left != null)
        {
            return left;
        }
        else
        {
            return right;
        }
    }
}
// @lc code=end
