/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */
#include "cpp_includes.h"
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
    ListNode *detectCycle(ListNode *head) {
        if (!head) return head;

        auto fast = head;
        auto slow = head;

        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;

            if (fast == slow) {
                auto begin = head;

                while (slow != begin) {
                    slow = slow->next;
                    begin = begin->next;
                }
                return slow;
            }
        }

        return NULL;
    }
};
// @lc code=end
