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
    if (!head) return head;

    unordered_map<Node*, Node*> cache;
    auto node = head;
    while (node) {
      auto n = new Node(node->val);
      cache[node] = n;
      node = node->next;
    }

    node = head;
    while (node) {
      auto n = cache[node];
      n->next = cache[node->next];
      n->random = cache[node->random];
      node = node->next;
    }

    return cache[head];
  }
};
// @lc code=end
