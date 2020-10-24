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
    bool isPalindrome(ListNode *head) {
        if (!head || !head->next)
            return true;

        // pre - 记录慢指针的前一个节点，用来分割链表
        // slow - 慢指针，找到链表中间分位置，作为分割
        auto pre = head, slow = head, fast = head;

        while (fast && fast->next) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = NULL; // 分割链表

        auto cur1 = head; // 前半部分
        auto cur2 =
            reverseList(slow); // 反转后半部分，
                               //总链表长度如果是奇数，cur2比cur1多一个节点

        if (!fast)
            slow = slow->next;

        while (cur1) {
            if (cur1->val != cur2->val)
                return false;
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        return true;
    }

    ListNode *reverseList(ListNode *head) {
        ListNode *temp = NULL, *pre = NULL, *cur = head;
        while (cur) {
            temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }
};
// @lc code=end
