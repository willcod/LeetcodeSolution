/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;

        ListNode dummy(0);
        dummy.next = head;
        auto pre = &dummy;
        while (pre && pre->next) {
            auto node = pre->next;
            if (!node->next || node->val != node->next->val) {
                pre = node;
            } else {
                while (node->next && node->val == node->next->val) {
                    node = node->next;
                }
                pre->next = node->next;
            }
        }


        return dummy.next;
    }
};
// @lc code=end

