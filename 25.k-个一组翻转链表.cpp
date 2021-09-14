/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy;
        dummy.next = head;
        auto cur = &dummy, last = &dummy;

        int count = 0;
        while (cur) {
            count++;
            cur = cur->next;

            if (count == k && cur) {
                auto next = last->next;
                while (--count) {
                    auto temp = last->next;
                    last->next = temp->next;
                    temp->next = cur->next;
                    cur->next = temp;
                }
                last = cur = next;
            }
        }
        return dummy.next;
    }
};
// @lc code=end
