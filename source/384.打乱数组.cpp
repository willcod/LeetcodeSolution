/*
 * @lc app=leetcode.cn id=384 lang=cpp
 *
 * [384] 打乱数组
 */
#include "cpp_includes.h"
// @lc code=start

class Solution {
 private:
  vector<int> _nums;

 public:
  Solution(vector<int>& nums) { _nums = nums; }

  /** Resets the array to its original configuration and return it. */
  vector<int> reset() { return _nums; }

  /** Returns a random shuffling of the array. */
  vector<int> shuffle() {
    vector<int> vec(_nums);
    for (int i = vec.size() - 1; i > 0; i--) {
      swap(vec[i], vec[rand() % (i + 1)]);
    }
    return vec;
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
// @lc code=end
