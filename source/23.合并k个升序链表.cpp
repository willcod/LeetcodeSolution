/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
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
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.empty()) return NULL;

    int n = lists.size();
    int interval = 1;
    while (interval < n) {
      for (int i = 0; i < n - interval; i += interval * 2) {
        lists[i] = merge2Lists(lists[i], lists[i + interval]);
      }
      interval *= 2;
    }
    return lists[0];
  }

  ListNode* merge2Lists(ListNode* l1, ListNode* l2) {
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;

    if (l1->val <= l2->val) {
      l1->next = merge2Lists(l1->next, l2);
      return l1;
    } else {
      l2->next = merge2Lists(l2->next, l1);
      return l2;
    }
  }
};
// @lc code=end
