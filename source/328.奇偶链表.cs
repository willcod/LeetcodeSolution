/*
 * @lc app=leetcode.cn id=328 lang=csharp
 *
 * [328] 奇偶链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution
{
  public ListNode OddEvenList(ListNode head)
  {
    if (head == null || head.next == null) return head;

    var odd = head;
    var even = head.next;
    var evenHead = head.next;

    while (even != null && even.next != null)
    {
      odd.next = even.next;
      odd = odd.next;
      even.next = odd.next;
      even = even.next;
    }

    odd.next = evenHead;
    return head;
  }
}
// @lc code=end

