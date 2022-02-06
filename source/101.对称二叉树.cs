/*
 * @lc app=leetcode.cn id=101 lang=csharp
 *
 * [101] 对称二叉树
 */

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
  public bool IsSymmetric(TreeNode root)
  {
    if (root == null) return false;

    return IsSymmetric(root.left, root.right);
  }

  private bool IsSymmetric(TreeNode left, TreeNode right)
  {
    if (left == null && right == null) return true;
    if (left == null || right == null) return false;

    return left.val == right.val && IsSymmetric(left.left, right.right)
    && IsSymmetric(left.right, right.left);
  }
}
// @lc code=end

