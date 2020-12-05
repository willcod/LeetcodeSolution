/*
 * @lc app=leetcode.cn id=328 lang=cpp
 *
 * [328] 奇偶链表
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
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return head;

        auto odd = head;
        auto eve = head->next;
        auto eveHead = head->next;

        while(eve && eve->next) {
            odd->next = eve->next;
            odd = odd->next;
            eve->next = odd->next;
            eve = eve->next;
        }

        odd->next = eveHead;
        return head;
    }
};
// @lc code=end

