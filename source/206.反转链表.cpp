/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;

        auto reverse = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;

        return reverse;
    }
};
// @lc code=end
