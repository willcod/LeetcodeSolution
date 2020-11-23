/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;

        auto slow = head;
        auto fast = head;
        ListNode* pre = nullptr;

        while (fast && fast->next) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        pre->next = nullptr;
        auto l1 = sortList(head);
        auto l2 = sortList(slow);

        return merge2list(l1, l2);
    }

    ListNode* merge2list(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;

        if (l1->val < l2->val) {
            l1->next = merge2list(l1->next, l2);
            return l1;
        } else {
            l2->next = merge2list(l2->next, l1);
            return l2;
        }
    }
};
// @lc code=end
