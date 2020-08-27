/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode head;
    ListNode* tail = &head;

    int sum = 0;
    while (l1 || l2 || sum > 0) {
      if (l1) sum += l1->val;
      if (l2) sum += l2->val;

      tail->next = new ListNode(sum % 10);
      tail = tail->next;
      sum /= 10;

      l1 = l1 ? l1->next : NULL;
      l2 = l2 ? l2->next : NULL;
    }

    return head.next;
  }
};
// @lc code=end
