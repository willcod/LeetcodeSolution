/*
 * @lc app=leetcode.cn id=147 lang=cpp
 *
 * [147] 对链表进行插入排序
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
    ListNode* insertionSortList(ListNode* head) {
        if (!head) return head;
        ListNode dummy;
        auto pre = &dummy;

        auto node = head;
        while (node) {
            auto cur = node;
            node = node->next;

            if (cur->val < pre->val) pre = &dummy;
            while (pre->next && cur->val > pre->next->val) pre = pre->next;

            cur->next = pre->next;
            pre->next = cur;
        }

        return dummy.next;
    }
};
// @lc code=end
