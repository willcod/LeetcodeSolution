/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
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
    void reorderList(ListNode* head) {
        if (!head) return;
        ListNode* p = head;
        ListNode* q = getMidNode(head);
        q = reverseList(q);
        mergeList(p, q);
    }

    ListNode* getMidNode(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (slow && fast && fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = slow->next;
        slow->next = nullptr;
        return mid;
    }

    ListNode* reverseList(ListNode* root) {
        ListNode *prev = NULL, *next = root, *curr = root;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
        // returning head of reversed list
    }

    void mergeList(ListNode* p, ListNode* q) {
        ListNode* tmp;
        while (q) {
            tmp = p->next;  // store address of next
            p->next = q;    // link to 2nd list
            q = q->next;    // increase 2nd list pointer
            p = p->next;
            p->next = tmp;  // link to 1st list
            p = p->next;    // increase 1st list pointer
        }
    }
};
// @lc code=end
class Solution {
   public:
    void reorderList(ListNode* head) {
        if (!head) return;

        vector<ListNode*> v;

        ListNode* node = head;
        while (node) {
            v.push_back(node);
            node = node->next;
        }

        int left = 0;
        int right = v.size() - 1;
        while (left < right) {
            v[left]->next = v[right];
            v[right]->next = v[left + 1];
            left++;
            right--;
        }
        v[left]->next = NULL;
    }
};