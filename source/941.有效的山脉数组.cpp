/*
 * @lc app=leetcode.cn id=941 lang=cpp
 *
 * [941] 有效的山脉数组
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if (arr.size() < 3) return false;

        int left = 0;
        int right = arr.size() - 1;

        while (left < arr.size() && arr[left] < arr[left+1]) left++;
        while (right > 0 && arr[right] < arr[right-1]) right--;

        if (left == arr.size() - 1 || right == 0) return false;

        return left == right;
    }
};
// @lc code=end

