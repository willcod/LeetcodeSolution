/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */
#include "cpp_includes.h"
// @lc code=start
class MyQueue {
   public:
    /** Initialize your data structure here. */
    MyQueue() {}

    /** Push element x to the back of queue. */
    void push(int x) { inStk.push(x); }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (outStk.empty()) {
            in2out();
        }
        int x = outStk.top();
        outStk.pop();
        return x;
    }

    /** Get the front element. */
    int peek() {
        if (outStk.empty()) {
            in2out();
        }
        return outStk.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() { return inStk.empty() && outStk.empty(); }

   private:
    void in2out() {
        while (!inStk.empty()) {
            outStk.push(inStk.top());
            inStk.pop();
        }
    }

   private:
    stack<int> inStk, outStk;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end
