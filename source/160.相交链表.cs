/*
 * @lc app=leetcode.cn id=160 lang=csharp
 *
 * [160] 相交链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) { val = x; }
 * }
 */
public class Solution
{
  public ListNode GetIntersectionNode(ListNode headA, ListNode headB)
  {
    if (headA == null || headB == null) return null;

    var pA = headA;
    var pB = headB;

    while (pA != pB)
    {
      pA = pA == null ? headB : pA.next;
      pB = pB == null ? headA : pB.next;
    }

    return pA;
  }
}
// @lc code=end

