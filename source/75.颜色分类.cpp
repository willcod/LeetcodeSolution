/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = 0;
        int blue = nums.size()-1;

        for (int i = 0; i <= blue; i++) {
            while (i <= blue && nums[i] == 2) {
                swap(nums[i], nums[blue--]);
            }

            if (nums[i] == 0){
                swap(nums[i], nums[red++]);
            }
        }
    }
};
// @lc code=end

