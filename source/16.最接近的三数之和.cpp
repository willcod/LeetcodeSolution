/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int res = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < n; i++) {
            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (abs(res - target) > abs(sum - target)) {
                    res = sum;
                }

                if (sum > target) {
                    right--;
                } else if (sum < target) {
                    left++;
                } else {
                    return sum;
                }
            }
        }
        return res;
    }
};
// @lc code=end
