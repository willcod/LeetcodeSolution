/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4) return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < nums.size(); i++) {
            int targetof3 = target - nums[i];
            for (int j = i + 1; j < nums.size(); j++) {
                int targetof2 = targetof3 - nums[j];

                int left = j + 1;
                int right = nums.size() - 1;

                while (left < right) {
                    int sumof2 = nums[left] + nums[right];
                    if (sumof2 == targetof2) {
                        res.push_back(
                            {nums[i], nums[j], nums[left], nums[right]});

                        while (left < right && nums[right] == nums[right - 1])
                            right--;
                        while (left < right && nums[left] == nums[left + 1])
                            left++;
                        right--;
                        left++;
                    } else if (sumof2 > targetof2)
                        right--;
                    else
                        left++;
                }
                while (j + 1 < nums.size() && nums[j] == nums[j + 1]) j++;
            }
            while (i + 1 < nums.size() && nums[i] == nums[i + 1]) i++;
        }

        return res;
    }
};
// @lc code=end
