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
        vector<int> res(nums1.size(), -1);
        unordered_map<int, int> hash2;
        for (int i = 0; i < nums2.size(); i++) {
            hash2[nums2[i]] = i;
        }

        for (int i = 0; i < nums1.size(); i++) {
            int start = hash2[nums1[i]];
            for (int j = start + 1; j < nums2.size(); j++) {
                if (nums1[i] < nums2[j]) {
                    res[i] = nums2[j];
                    break;
                }
            }
        }
        return res;
    }
};
// @lc code=end
