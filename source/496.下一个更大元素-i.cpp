/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;

        unordered_map<int, int> address;
        for (int i = 0; i < nums2.size(); i++) {
            address[nums2[i]] = i;
        }

        for (int i = 0; i < nums1.size(); i++) {
            int j = address[nums1[i]];
            for (;j<nums2.size(); j++){
                if (nums1[i] < nums2[j]) {
                    res.push_back(nums2[j]);
                    break;
                }
            }
            if (j == nums2.size()) res.push_back(-1);
        }

        return res;
    }
};
// @lc code=end

