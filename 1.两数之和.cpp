/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++) {
            int nums2 = target - nums[i];
            if (hash.count(nums2))
                return {hash[nums2], i};
            else
                hash[nums[i]] = i;
        }

        return {-1, -1};
    }
};
// @lc code=end

