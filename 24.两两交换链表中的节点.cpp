/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// class Solution {
// public:
//     ListNode* swapPairs(ListNode* head) {
//         if (!head || !head->next) return head;

//         auto next = head->next;
//         head->next = swapPairs(next->next);
//         next->next = head;

//         return next;
//     }
// };

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;

        auto next = head->next;
        head->next = swapPairs(next->next);
        next->next = head;

        return next;
    }
};
// @lc code=end

