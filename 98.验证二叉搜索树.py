#
# @lc app=leetcode.cn id=98 lang=python3
#
# [98] 验证二叉搜索树
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.pre = None

    def isValidBST(self, root: TreeNode) -> bool:
        if root is None: return True

        if self.isValidBST(root.left) == False: return False

        if self.pre is not None:
            if root.val <= self.pre.val: return False
        self.pre = root

        return self.isValidBST(root.right)

# @lc code=end

