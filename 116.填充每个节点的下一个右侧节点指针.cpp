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
        //层序遍历
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

        // 没有创建新树，所以可以先直接写return root
        return root;
    }
};
// @lc code=end
