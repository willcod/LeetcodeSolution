/*
 * @lc app=leetcode.cn id=117 lang=cpp
 *
 * [117] 填充每个节点的下一个右侧节点指针 II
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
        if (!root) return NULL;

        queue<Node*> q;
        q.push(root);

        Node *node, *pre;

        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                if (i == 0) {
                    pre = q.front();
                    q.pop();
                    node = pre;
                } else {
                    node = q.front();
                    q.pop();
                    pre->next = node;
                    pre = pre->next;
                                }

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            pre->next = NULL;
        }
        return root;
    }
};
// @lc code=end
