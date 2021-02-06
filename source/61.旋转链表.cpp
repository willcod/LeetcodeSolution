/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next) return head;

        auto tail = head;
        int len = 1;
        while (tail->next) {
            tail = tail->next;
            len++;
        }

        k = k % len;
        if (!k) return head;

        auto nhead = head;
        auto pre = head;

        for (int i = 0; i < len-k; i++) {
            pre = nhead;
            nhead = nhead->next;
        }

        pre->next = nullptr;
        tail->next = head;
        return nhead;
    }
};
// @lc code=end

