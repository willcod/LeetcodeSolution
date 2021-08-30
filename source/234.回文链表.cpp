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
    stack<ListNode*> stk;

    ListNode* cur = head;

    while (cur) {
      stk.push(cur);
      cur = cur->next;
    }

    cur = head;
    while (cur) {
      if (stk.top()->val != cur->val) return false;

      stk.pop();
      cur = cur->next;
    }
    return true;
  }
};
// @lc code=end
