/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
 public:
  bool isValid(string s) {
    deque<char> stack;

    for (char c : s) {
      if (c == '(' || c == '[' || c == '{') {
        stack.push_front(c);
      }

      if (c == ')') {
        if (stack.empty() || stack.front() != '(') return false;
        stack.pop_front();
      }

      if (c == ']') {
        if (stack.empty() || stack.front() != '[') return false;
        stack.pop_front();
      }

      if (c == '}') {
        if (stack.empty() || stack.front() != '{') return false;
        stack.pop_front();
      }
    }

    return stack.empty();
  }
};
// @lc code=end
