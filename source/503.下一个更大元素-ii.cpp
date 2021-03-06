/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 */
#include "cpp_includes.h"
/*
224/224 cases passed (44 ms)
Your runtime beats 72.22 % of cpp submissions
Your memory usage beats 88.92 % of cpp submissions (22.4 MB)*/
class Solution {
   public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> stk;
        for (int i = 0; i < n * 2 - 1; i++) {
            while (!stk.empty() && nums[stk.top()] < nums[i % n]) {
                res[stk.top()] = nums[i % n];
                stk.pop();
            }
            stk.push(i % n);
        }
        return res;
    }
};

// @lc code=start
class Solution {
   public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> stk;
        for (int i = 0; i < n * 2 - 1; i++) {
            while (!stk.empty() && nums[stk.top()] < nums[i % n]) {
                res[stk.top()] = nums[i % n];
                stk.pop();
            }
            stk.push(i % n);
        }
        return res;
    }
};
// @lc code=end
