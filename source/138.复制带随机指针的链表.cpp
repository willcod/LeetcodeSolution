/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 复制带随机指针的链表
 */
#include "cpp_includes.h"
// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
   public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;

        unordered_map<Node*, Node*> hash;
        auto cur = head;
        while (cur) {
            hash[cur] = new Node(cur->val);
            cur = cur->next;
        }

        cur = head;
        while (cur) {
            auto newNode = hash[cur];
            newNode->next = hash[cur->next];
            newNode->random = hash[cur->random];
            cur = cur->next;
        }

        return hash[head];
    }
};
// @lc code=end
