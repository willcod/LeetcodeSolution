/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层次遍历 II
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
 public:
  vector<vector<int>> levelOrderBottom(TreeNode* root) {
      int d = depth(root);
      vector<vector<int>> res(d);
      levelOrder(res, root, d-1);
      return res;
  }

  void levelOrder(vector<vector<int>>& res, TreeNode* root, int level) {
      if (!root) return;
      res[level].push_back(root->val);
      levelOrder(res, root->left, level-1);
      levelOrder(res, root->right, level-1);
  }

  int depth(TreeNode* root) {
      if (!root) return 0;
      return max(depth(root->left), depth(root->right)) + 1;
  }
};
// @lc code=end

//DFS
/*
34/34 cases passed (0 ms)
Your runtime beats 100 % of cpp submissions
Your memory usage beats 41.33 % of cpp submissions (11.8 MB)
*/
class Solution {
 public:
  vector<vector<int>> levelOrderBottom(TreeNode* root) {
    int d = depth(root);
    vector<vector<int>> res(d);
    levelOrder(res, root, d - 1);
    return res;
  }

  void levelOrder(vector<vector<int>>& res, TreeNode* root, int level) {
    if (!root) return;
    res[level].push_back(root->val);
    levelOrder(res, root->left, level - 1);
    levelOrder(res, root->right, level - 1);
  }

  int depth(TreeNode* root) {
    if (!root) return 0;
    return max(depth(root->left), depth(root->right)) + 1;
  }
};


// BFS, stack
class Solution {
 public:
  vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> res;
    if (!root) return res;

    stack<vector<int>> stk;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
      int n = q.size();
      vector<int> level;
      for (int i = 0; i < n; i++) {
        auto node = q.front();
        q.pop();
        level.push_back(node->val);
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
      }
      stk.push(level);
    }

    while (!stk.empty()) {
      res.push_back(stk.top());
      stk.pop();
    }
    return res;
  }
};

