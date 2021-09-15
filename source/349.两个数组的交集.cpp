/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> res;
        unordered_set<int> set1({nums1.begin(), nums1.end()});

        for (int n : nums2) {
            if (set1.count(n)) {
                res.insert(n);
            }
        }

        return {res.begin(), res.end()};
    }
};
// @lc code=end
