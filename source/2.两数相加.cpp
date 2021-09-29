/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode dummyNode;
    ListNode* cur = &dummyNode;

    int sum = 0;
    while (l1 || l2 || sum) {
      if (l1) sum += l1->val;
      if (l2) sum += l2->val;
      cur->next = new ListNode(sum % 10);
      sum /= 10;
      cur = cur->next;
      if (l1) l1 = l1->next;
      if (l2) l2 = l2->next;
    }
    return dummyNode.next;
  }
};
// @lc code=end
