/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */
#include "cpp_includes.h"
// @lc code=start
class MinStack {
 private:
  stack<int> _stk;
  stack<int> _minStk;

 public:
  /** initialize your data structure here. */
  MinStack() {
      _minStk.push(INT_MAX);
  }

  void push(int val) {
    _stk.push(val);
    _minStk.push(min(val, _minStk.top()));
  }

  void pop() {
    _stk.pop();
    _minStk.pop();
  }

  int top() { return _stk.top(); }

  int getMin() { return _minStk.top(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end
