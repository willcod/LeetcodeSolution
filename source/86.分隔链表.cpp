/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* large = new ListNode(0);
        ListNode* largehead = large;
        ListNode* small = new ListNode(0);
        ListNode* smallhead = small;

        while (head) {
            if (head->val < x) {
                small->next = head;
                small = small->next;
            } else {
                large->next = head;
                large = large->next;
            }
            head = head->next;
        }
        large->next = nullptr;
        small->next = largehead->next;

        return smallhead->next;
    }
};
// @lc code=end
