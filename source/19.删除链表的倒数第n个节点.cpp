/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第N个节点
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy;
        dummy.next = head;

        auto fast = &dummy;
        auto slow = &dummy;

        while (n--) {
            fast = fast->next;
        }

        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }

        auto skip = slow->next;
        slow->next = slow->next->next;

        delete skip;

        return head;
    }
};
// @lc code=end
