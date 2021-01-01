/*
 * @lc app=leetcode.cn id=605 lang=cpp
 *
 * [605] 种花问题
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for (int i = 0; i < flowerbed.size(); i += 2) {
            if (flowerbed[i] == 1)
                continue;
            else if (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0) {
                n--;
            } else {
                i++;
            }
        }

        return n <= 0;
    }
};
// @lc code=end
