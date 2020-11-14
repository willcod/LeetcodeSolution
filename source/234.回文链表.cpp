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
        // the most easy way is use another data structure to hold the data, then compare
        // use a stack to reverse the link
        if (!head) return true;

        stack<ListNode*> stk;
        auto node = head;

        while (node) {
            stk.push(node);
            node = node->next;
        }

        node = head;
        while (!stk.empty()) {
            if (stk.top()->val != node->val) return false;
            else{
                stk.pop();
                node = node->next;
            }
        }
        return true;
    }
};
// @lc code=end

