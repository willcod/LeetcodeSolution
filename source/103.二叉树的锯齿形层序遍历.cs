/*
 * @lc app=leetcode.cn id=103 lang=csharp
 *
 * [103] 二叉树的锯齿形层序遍历
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
  public IList<IList<int>> ZigzagLevelOrder(TreeNode root)
  {
    var result = new List<IList<int>>();
    if (root == null) return result;
    var queue = new Queue<TreeNode>();
    queue.Enqueue(root);

    while (queue.Count != 0)
    {
      var n = queue.Count;
      var level = new List<int>();
      for (int i = 0; i < n; i++)
      {
        var node = queue.Dequeue();
        level.Add(node.val);
        if (node.left != null) queue.Enqueue(node.left);
        if (node.right != null) queue.Enqueue(node.right);
      }
      if (result.Count % 2 == 1)
      {
        level.Reverse();
      }
      result.Add(level);
    }

    return result;
  }
}
// @lc code=end

