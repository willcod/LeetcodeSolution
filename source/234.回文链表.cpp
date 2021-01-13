/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;

        auto pre = head, slow = head, fast = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            pre = slow;
            slow = slow->next;
        }

        pre->next = nullptr;
        auto l1 = head;
        auto l2 = reverseList(slow);
        
        if (!fast) slow = slow->next;

        while (l1 && l2) {
            if (l1->val != l2->val) return false;
            l1 = l1->next;
            l2 = l2->next;
        }
        return true;
    }

    ListNode* reverseList(ListNode*head) {
        if (!head || !head->next) return head;

        ListNode* pre = nullptr;
        auto cur = head;
        while(cur) {
            auto next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};
// @lc code=end

