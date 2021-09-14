#
# @lc app=leetcode.cn id=61 lang=python
#
# [61] 旋转链表
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def rotateRight(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        if not head or not head.next: return head
        len_ = 0
        cur = head
        while cur:
            len_ += 1
            cur = cur.next
        
        k %= len_
        if k == 0: return head

        fast, slow = head, head
        while k:
            fast = fast.next
            k -= 1
        
        while fast.next:
            fast = fast.next
            slow = slow.next
        
        newHead = slow.next
        slow.next = None

        fast.next = head
        return newHead
# @lc code=end

