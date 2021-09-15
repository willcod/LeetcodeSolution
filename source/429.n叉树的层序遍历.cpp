/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N叉树的层序遍历
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (!root) return {};
        vector<vector<int>> results;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int len = q.size();
            vector<int> level;
            for (int i = 0; i < len; i++) {
                auto node = q.front();
                q.pop();
                level.push_back(node->val);

                for (auto n : node->children) {
                    q.push(n);
                }
            }
            results.push_back(level);
        }

        return results;
    }
};
// @lc code=end

