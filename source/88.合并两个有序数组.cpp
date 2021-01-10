/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        nums1.resize(m);
        for (auto num : nums2)
            nums1.push_back(num);
        
        sort(nums1.begin(), nums1.end());
    }
};
// @lc code=end
