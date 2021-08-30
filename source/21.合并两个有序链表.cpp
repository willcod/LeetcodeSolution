/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy;
        ListNode* zip = &dummy;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                zip->next = l1;
                l1 = l1->next;
            } else {
                zip->next = l2;
                l2 = l2->next;
            }
            zip = zip->next;
        }

        zip->next = l1 ? l1 : l2;

        return dummy.next;
    }
};
// @lc code=end
