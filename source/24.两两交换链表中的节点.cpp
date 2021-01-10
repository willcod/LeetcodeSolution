/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode dummy(0);
        dummy.next = head;
        auto* p = &dummy;

        while (p->next && p->next->next) {
            auto n1 = p->next;
            auto n2 = p->next->next;

            p->next = n2;
            n1->next = n2->next;
            n2->next = n1;
            p = n1;
        }

        return dummy.next;
    }   
};
// @lc code=end

