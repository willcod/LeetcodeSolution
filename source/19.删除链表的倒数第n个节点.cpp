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
        vector<ListNode*> nodeVec;
        ListNode dummy(0);
        dummy.next = head;
        auto node = &dummy;

        for (int i = 0; i < n; i++) {
            node = node->next;
        }

        auto back = &dummy;
        while (node->next) {
            node = node->next;
            back = back->next;
        }

        back->next = back->next->next;
        
        return dummy.next;
    }
};
// @lc code=end

