/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> counts;
        vector<int> result;
        for (auto n : nums1) {
            counts[n]++;
        }

        for (auto m : nums2) {
            if (counts[m] > 0) {
                result.push_back(m);
                counts[m]--;
            }
        }

        return result;
    }
};
// @lc code=end

