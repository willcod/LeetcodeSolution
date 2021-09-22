/*
 * @lc app=leetcode.cn id=461 lang=cpp
 *
 * [461] 汉明距离
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
public:
    int hammingDistance(int x, int y) {
        int s = x ^ y;
        int count = 0;

        while (s) {
            count += s & 1;
            s >>= 1;
        }

        return count;
    }
};
// @lc code=end

