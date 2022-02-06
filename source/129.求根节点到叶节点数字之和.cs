/*
 * @lc app=leetcode.cn id=129 lang=csharp
 *
 * [129] 求根节点到叶节点数字之和
 */
using csharp;

// @lc code=start
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution
{
    public int SumNumbers(TreeNode root, int sum = 0)
    {
        if (root == null) return 0;
        sum = sum * 10 + root.val;
        if (root.left == null && root.right == null) return sum;
        return SumNumbers(root.left, sum) + SumNumbers(root.right, sum);
    }
}
// @lc code=end
