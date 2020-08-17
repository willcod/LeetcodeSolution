// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem88.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n -1;
        int f = m + n -1;

        while( j >= 0)
            nums1[f--] = (i >= 0) && nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
    }
};
// @lc code=end

