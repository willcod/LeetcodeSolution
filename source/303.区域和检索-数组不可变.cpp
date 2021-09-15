/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
 */
#include "cpp_includes.h"
// @lc code=start
class NumArray {
   public:
    NumArray(vector<int>& nums) : result(nums.size() + 1, 0) {
        for (int i = 0; i < nums.size(); i++) {
            result[i + 1] = result[i] + nums[i];
        }
    }

    int sumRange(int i, int j) { return result[j + 1] - result[i]; }

   private:
    vector<int> result;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
// @lc code=end
