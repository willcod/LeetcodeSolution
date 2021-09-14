#
# @lc app=leetcode.cn id=92 lang=python
#
# [92] 反转链表 II
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def reverseBetween(self, head, left, right):
        """
        :type head: ListNode
        :type left: int
        :type right: int
        :rtype: ListNode
        """
        count = 1
        dummy = ListNode(0)
        dummy.next = head
        pre = dummy
        while pre.next and count < left:
            pre = pre.next
            count += 1
        cur = pre.next
        tail = cur
        while cur and count <= right:
            nxt = cur.next
            cur.next = pre.next
            pre.next = cur
            tail.next = nxt
            cur = nxt
            count += 1
        return dummy.next
# @lc code=end

