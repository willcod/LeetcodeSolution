/*
 * @lc app=leetcode.cn id=116 lang=cpp
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */
#include "cpp_includes.h"
// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
 public:
  Node* connect(Node* root) {
    if (!root) return root;

    queue<Node*> q;
    q.push(root);

    Node *pre, *cur;
    while (!q.empty()) {
      int size = q.size();
      for (int i = 0; i < size; i++) {
        if (i == 0) {
          pre = q.front();
          q.pop();
          cur = pre;
        } else {
          cur = q.front();
          q.pop();

          pre->next = cur;
          pre = pre->next;
        }

        if (cur->left) q.push(cur->left);
        if (cur->right) q.push(cur->right);
      }

      pre->next = nullptr;
    }

    return root;
  }
};
// @lc code=end
