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

        vector<vector<int>> result;
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();
            vector<int> level;

            for (int i = 0; i < n; i++) {
                auto node = q.front();
                q.pop();

                level.push_back(node->val);

                for (auto c : node->children) {
                    q.push(c);
                }
            }
            result.push_back(level);
        }
        return result; 
    }
};
// @lc code=end

