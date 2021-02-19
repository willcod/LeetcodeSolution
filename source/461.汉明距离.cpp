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
        return bitset<32>(x^y).count();
    }
};
// @lc code=end

