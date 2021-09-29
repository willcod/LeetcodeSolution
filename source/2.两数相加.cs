/*
 * @lc app=leetcode.cn id=2 lang=csharp
 *
 * [2] 两数相加
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
  public ListNode AddTwoNumbers(ListNode l1, ListNode l2)
  {
    var dummy = new ListNode();
    var cur = dummy;

    int sum = 0;
    while (l1 != null || l2 != null || sum != 0)
    {
      if (l1 != null) sum += l1.val;
      if (l2 != null) sum += l2.val;

      cur.next = new ListNode(sum % 10);
      sum /= 10;
      cur = cur.next;

      if (l1 != null) l1 = l1.next;
      if (l2 != null) l2 = l2.next;
    }
    return dummy.next;
  }
}
// @lc code=end

