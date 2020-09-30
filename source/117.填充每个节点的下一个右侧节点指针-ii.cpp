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

        while(!q.empty()) {
            int len = q.size();
            Node *node, *preNode;
            for (int i = 0; i < len; i++) {
                if (i == 0) {
                    preNode = q.front();
                    q.pop();
                    node = preNode;
                } else {
                    node = q.front();
                    q.pop();
                    preNode->next = node;
                    preNode = preNode->next;
                }
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            preNode->next = NULL;
        }
        return root;
    }
};
// @lc code=end

