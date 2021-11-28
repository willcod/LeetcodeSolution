/*
 * @lc app=leetcode.cn id=559 lang=cpp
 *
 * [559] N 叉树的最大深度
 */
#include "cpp_includes.h"
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
  int maxDepth(Node* root) {
    if (!root) return 0;

    int depth = 0;

    auto children = root->children;
    for (auto child : children) {
      int d = maxDepth(child);
      depth = max(depth, d);
    }
    return ++depth;
  }
};
// @lc code=end
