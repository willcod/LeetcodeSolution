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
        unordered_map<int, int> nums2pos;
        for (int i = 0; i < nums2.size(); i++) {
            nums2pos[nums2[i]] = i;
        }

        vector<int> res(nums1.size(), -1);
        for (int i = 0; i < nums1.size(); i++) {
            int start = nums2pos[nums1[i]];
            for (int j = start+1; j < nums2.size(); j++) {
                if (nums2[j] > nums1[i]) {
                    res[i] = nums2[j];
                    break;
                }
            }
        }
        return res;
    }
};
// @lc code=end

