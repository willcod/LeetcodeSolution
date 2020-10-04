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
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode front(0);
        front.next = head;
        auto cur = &front;
        auto last = &front;

        int count = 0;
        while (cur) {
            cur = cur->next;
            count++;

            if (count == k && cur) {
                auto mid = last->next;

                while(--count) {
                    auto temp = last->next;
                    last->next = temp->next;
                    temp->next = cur->next;
                    cur->next = temp;

                }
                last = cur = mid;
            }
        }
        return front.next;
    }
};
// @lc code=end

