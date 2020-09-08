/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为K的子数组
 */

// @lc code=start
class Solution {
 public:
  int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> hash;
    hash[0] = 1;
    int count = 0, pre = 0;
    for (int n : nums) {
      pre += n;
      if (hash.count(pre - k)) count += hash[pre - k];

      hash[pre]++;
    }
    return count;
  }
};
// @lc code=end
