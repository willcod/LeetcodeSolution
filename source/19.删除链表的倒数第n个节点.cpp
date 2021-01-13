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
        ListNode dummy(0);
        dummy.next = head;

        auto front = &dummy;
        auto back = &dummy;

        for (int  i = 0; i < n; i++) {
            front = front->next;
        }

        while (front->next) {
            front = front->next;
            back = back->next;
        }

        auto delNode = back->next;
        back->next = back->next->next;
        delete delNode;

        return dummy.next;
    }
};
// @lc code=end

