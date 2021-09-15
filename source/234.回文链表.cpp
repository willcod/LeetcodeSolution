/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 */
#include "cpp_includes.h"
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
 public:
  bool isPalindrome(ListNode* head) {
      if (!head || !head->next) return true;

      auto pre = head;
      auto slow = head;
      auto fast = head;
      while (fast && fast->next) {
          pre = slow;
          slow = slow->next;
          fast = fast->next->next;
      }

      pre->next = NULL;
      auto cur1 = head;
      auto cur2 = reverseList(slow);

      if (!fast) slow = slow->next;

      while(cur1&&cur2) {
          if (cur1->val != cur2->val) return false;
          cur1 = cur1->next;
          cur2 = cur2->next;
      }

      return true;
  }

  ListNode* reverseList(ListNode* head) {
      if (!head || !head->next) return head;

      auto cur = head;
      ListNode* pre = NULL;
      while (cur) {
          auto next = cur->next;
          cur->next = pre;
          pre = cur;
          cur = next;
      }
      return pre;
  }
};
// @lc code=end
