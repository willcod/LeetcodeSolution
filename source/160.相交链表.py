#
# @lc app=leetcode.cn id=160 lang=python3
#
# [160] 相交链表
#
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None
# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        if headA == None or headB == None: return None

        pA = headA
        pB = headB

        while pA != pB:
            pA = headB if pA == None else pA.next
            pB = headA if pB == None else pB.next

        return pA
        
# @lc code=end

