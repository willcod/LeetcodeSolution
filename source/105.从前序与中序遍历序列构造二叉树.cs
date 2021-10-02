/*
 * @lc app=leetcode.cn id=105 lang=csharp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 */
using csharpnaming;
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
  public TreeNode BuildTree(int[] preorder, int[] inorder)
  {
    var inDict = new Dictionary<int, int>();
    for (int i = 0; i < inorder.Length; i++)
    {
      inDict[inorder[i]] = i;
    }

    int pos = 0;
    return BuildTree(preorder, inDict, 0, inorder.Length - 1, ref pos);
  }

  private TreeNode BuildTree(int[] preorder, Dictionary<int, int> inDict, int ibegin, int iend, ref int pos)
  {
    if (pos == preorder.Length || ibegin > iend) return null;

    var node = new TreeNode(preorder[pos]);
    var i = inDict[preorder[pos]];
    pos++;

    node.left = BuildTree(preorder, inDict, ibegin, i - 1, ref pos);
    node.right = BuildTree(preorder, inDict, i + 1, iend, ref pos);

    return node;
  }
}
// @lc code=end

